#include <bits/stdc++.h>

using namespace std;

struct Color
{
    uint8_t r, g, b;
    
    Color() : r(0), g(0), b(0) {}
    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(b), b(b) {}
};

struct Image
{
    int imageId;
    int width, height;
    Color* pixels;

    Image(int imageId, int width, int height) :
        imageId(imageId),
        width(width),
        height(height),
        pixels(new Color[width*height]) {}

    ~Image()
    {
        delete[] pixels;
    }

    void printImage()
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                auto& pixel = pixels[y * width + x];
                cout << "\033[48;2;" << 
                     static_cast<int>(pixel.r) << ";" << 
                     static_cast<int>(pixel.g) << ";" << 
                     static_cast<int>(pixel.b) << 
                     "m   \033[0m";
            }
            cout << '\n';
        }
    }

    void flipImage(bool horizontal, bool vertical)
    {
        if(!horizontal && !vertical) return;

        auto* flipped = new Color[width*height];
        for(int y = 0; y < height; y++)
        {
            int fY = height-1 - y;
            for(int x = 0; x < width; x++)
            {
                int fX = width-1 - x;
                flipped[(horizontal ? fY : y) * width + (vertical ? fX : x)] = pixels[y * width + x];
            }
        }

        delete[] pixels;
        pixels = flipped;
    }

    void insertChunk(int x, int y, int width, int height, const unique_ptr<Color[]>& chunk)
    {
        for(int j = max(0, y); j < min(this->height, y+height); j++)
        for(int i = max(0, x); i < min(this->width, x+width); i++)
        {
            int chunkX = i-x;
            int chunkY = j-y;
            pixels[j * this->width + i] = chunk[chunkY * width + chunkX];
        }
    }

    void removeChunk(int x, int y, int width, int height, const Color& color)
    {
        for(int j = max(0, y); j < min(this->height, y+height); j++)
        for(int i = max(0, x); i < min(this->width, x+width); i++)
            pixels[j * this->width + i] = color;
    }

    void blit(Image* dst, int srcX, int srcY, int srcWidth, int srcHeight, int dstX, int dstY)
    {
        for(int j = max(0, srcY); j < min(this->height, srcY+srcHeight); j++)
        {
            int dstAbsY = dstY+(j-srcY);
            if(dstAbsY >= dst->height || dstAbsY < 0) continue;
            for(int i = max(0, srcX); i < min(this->width, srcX+srcWidth); i++)
            {
                int dstAbsX = dstX+(i-srcX);
                if(dstAbsX >= dst->width || dstAbsX < 0) continue;
                dst->pixels[dstAbsY * dst->width + dstAbsX] = pixels[j * this->width + i];
            }
        }
    }
};

struct ImageData
{
    Image* data;
    ImageData* next;

    ImageData(Image* data, ImageData* next = nullptr) : data(data), next(next) {}
};

struct ImageCollection
{
    ImageData* root;
    ImageData* head;

    ImageCollection() : root(nullptr), head(nullptr) {}

    ~ImageCollection()
    {
        auto* work = root;
        while(work)
        {
            delete work->data;
            auto* prev = work;
            work = work->next;
            delete prev;
        }
    }

    void add(Image* image)
    {
        auto* newData = new ImageData(image, nullptr);
        if(!root) root = newData;
        if(head) head->next = newData;
        head = newData;
    }

    Image* find(int imageId)
    {
        auto* work = root;
        while(work)
        {
            if(work->data->imageId == imageId) return work->data;
            else work = work->next;
        }

        return nullptr;
    }

    bool remove(int imageId)
    {
        auto* work = root;
        ImageData* beforeTarget = nullptr;
        ImageData* target = nullptr;
        while(work)
        {
            if(work->data->imageId == imageId) 
            {
                target = work;
                break;
            }
            else 
            {
                beforeTarget = work;
                work = work->next;
            }
        }
        if(!beforeTarget || !target) return false;
        beforeTarget->next = target->next;
        delete target->data;
        delete target;

        return true;
    }
};

#define DEBUG
#undef DEBUG
int main()
{   
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);  
#else
    freopen("input.txt", "r", stdin);
#endif

    int N;
    cin >> N;

    ImageCollection images{};
    while(N--)
    {
        string cmd;
        cin >> cmd;
        
        if(cmd == "cim")
        {
            int imageId, width, height;
            cin >> imageId >> width >> height;
            if(images.find(imageId))
            {
                cout << "invalid\n";
                continue;
            }
            auto* image = new Image(imageId, width, height);
            images.add(image);
        }
        else if(cmd == "dim")
        {
            int imageId;
            cin >> imageId;
            if(!images.remove(imageId))
            {
                cout << "invalid\n";
                continue;
            }
        }
        else if(cmd == "pim")
        {
            int imageId;
            cin >> imageId;
            auto* image = images.find(imageId);
            if(!image)
            {
                cout << "invalid\n";
                continue;
            }
            image->printImage();
        }
        else if(cmd == "fim")
        {
            int imageId;
            bool horizontal, vertical;
            cin >> imageId >> horizontal >> vertical;
            auto* image = images.find(imageId);
            if(!image)
            {
                cout << "invalid\n";
                continue;
            }
            image->flipImage(horizontal, vertical);
        }
        else if(cmd == "ich")
        {
            int imageId, x, y, width, height;
            cin >> imageId >> x >> y >> width >> height;
            auto* image = images.find(imageId);
            if(!image)
            {
                for(int i = 0; i < width*height*3; i++)
                {
                    int value;
                    cin >> value;
                }
                cout << "invalid\n";
                continue;
            }
            else
            {
                auto chunk = make_unique<Color[]>(width*height);
                for(int i = 0; i < width*height*3; i++)
                {
                    int value;
                    cin >> value;
                    if(i % 3 == 0) chunk[i / 3].r = static_cast<uint8_t>(value);
                    else if(i % 3 == 1) chunk[i / 3].g = static_cast<uint8_t>(value);
                    else if(i % 3 == 2) chunk[i / 3].b = static_cast<uint8_t>(value);
                }
                image->insertChunk(x, y, width, height, chunk);
            }
        }
        else if(cmd == "rch")
        {
            int imageId, x, y, width, height, colorR, colorG, colorB;
            cin >> imageId >> x >> y >> width >> height >> colorR >> colorG >> colorB;
            auto* image = images.find(imageId);
            if(!image)
            {
                cout << "invalid\n";
                continue;
            }
            image->removeChunk(x, y, width, height, 
            { 
                static_cast<uint8_t>(colorR), 
                static_cast<uint8_t>(colorG), 
                static_cast<uint8_t>(colorB)
            });
        }
        else if(cmd == "blt")
        {
            int srcImageId, dstImageId, srcX, srcY, srcWidth, srcHeight, dstX, dstY;
            cin >> srcImageId >> dstImageId >> srcX >> srcY >> srcWidth >> srcHeight >> dstX >> dstY;
            auto* srcImage = images.find(srcImageId);
            auto* dstImage = images.find(dstImageId);
            if(!srcImage && !dstImage)
            {
                cout << "bthInvalid\n";
                continue;
            }
            if(!srcImage)
            {
                cout << "srcInvalid\n";
                continue;
            }
            if(!dstImage)
            {
                cout << "dstInvalid\n";
                continue;
            }
            srcImage->blit(dstImage, srcX, srcY, srcWidth, srcHeight, dstX, dstY);
        }
    }
}