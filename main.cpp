#include <iostream>

#include "color.hpp"
#include "vec3.hpp"

// Usage ./main > image.ppm
int main(int argc, char **argv)
{
  // Image

  const int image_width = 256;
  const int image_height = 256;

  // Render
  std::cout << "P3\n"
            << image_width << ' ' << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) // row are written from top to bottom
  {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) // on each row pizels are written left to right
    {
      color pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
      write_color(std::cout, pixel_color);
    }
  }
  std::cerr << "\nDone.\n";
  return 0;
}