// CRTP (Curiously Recurring Template Pattern)
// VPtr and VTable can be avoided altogether through CRTP. CRTP is a design
// pattern in C++ in which a class X derives from a class template instantiation
// using X itself as template argument.
// More generally it is known as F-boud polymorphism.

#include <iostream> 
#include <chrono> 
using namespace std; 
  
typedef std::chrono::high_resolution_clock Clock; 
  
// To store dimensions of an image 
class Dimension 
{ 
public: 
    Dimension(int _X, int _Y) {mX = _X;  mY = _Y; } 
private: 
    int mX, mY; 
}; 

// Base class for all image types 
class Image 
{ 
public: 
    virtual void Draw() = 0; 
    virtual Dimension GetDimensionInPixels() = 0; 
protected: 
    int dimensionX; 
    int dimensionY; 
}; 
  
// For Tiff Images 
class TiffImage : public Image 
{ 
public: 
    void Draw() { } 
    Dimension GetDimensionInPixels() { 
        return Dimension(dimensionX, dimensionY); 
    } 
};

// Base class for all image types. The template
// parameter T is used to know type of derived
// class pointed by pointer.
template <class T>
class Image_CRTP
{
public:
    void Draw()
    {
        // Dispatch call to exact type
        static_cast<T*> (this)->Draw();
    }
    Dimension GetDimensionInPixels()
    {
        // Dispatch call to exact type
        return static_cast<T*> (this)->GetDimensionInPixels();
    }

protected:
    int dimensionX, dimensionY;
};


// For Tiff Images
class TiffImage_CRTP : public Image_CRTP<TiffImage_CRTP>
{
public:
    void Draw()
    {
        // Uncomment this to check method dispatch
        // cout << "TiffImage::Draw() called" << endl;
    }
    Dimension GetDimensionInPixels()
    {
        return Dimension(dimensionX, dimensionY);
    }
};

  
  
// Driver code that calls virtual function 
int main() 
{ 
	int n=1000;
    // An image type   
    Image* pImage = new TiffImage; 
    Image_CRTP<TiffImage_CRTP>* pImage_CRTP = new TiffImage_CRTP; 
  
    // Store time before virtual function calls 
    auto then = Clock::now(); 
  
    // Call Draw n times to make sure performance 
    // is visible 
    for (int i = 0; i < n; ++i) 
        pImage->Draw(); 
  
    // Store time after virtual function calls 
    auto now = Clock::now(); 
  
    cout << "VPtr Time taken: "
         << std::chrono::duration_cast 
           <std::chrono::nanoseconds>(now - then).count() 
         << " nanoseconds" << endl; 
    
  
    // Store time before virtual function calls 
    auto then_crtp = Clock::now(); 
  
    // Call Draw n times to make sure performance 
    // is visible 
    for (int i = 0; i < n; ++i) 
        pImage_CRTP->Draw(); 
  
    // Store time after virtual function calls 
    auto now_crtp = Clock::now(); 
  
    cout << "CRTP Time taken: "
         << std::chrono::duration_cast 
           <std::chrono::nanoseconds>(now_crtp - then_crtp).count() 
         << " nanoseconds" << endl;
	
	cout << "sizeof(Image) = " << sizeof(Image) << endl;
	cout << "sizeof(Image_CRTP) = " << sizeof(Image_CRTP<TiffImage_CRTP>) << endl;
  
    return 0; 
} 
