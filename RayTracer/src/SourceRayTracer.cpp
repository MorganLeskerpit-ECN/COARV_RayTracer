#include <iostream>
#include <test.h>
#include <fstream>

#include <vec3.h>
#include <color.h>

int main() {


    const int image_width = 960;
    const int image_height = 720;
    
    std::ofstream render_image("myRender.ppm");

    render_image << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j  = image_height-1; j>=0; j--){
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1), 0.25);
            write_color(render_image, pixel_color);
        }
    }

    render_image.close();
    std::cerr << "\nDone.\n";
    system("pause");
    return 0;
}