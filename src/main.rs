use skia_safe::{Canvas, Data, EncodedImageFormat, Image, ImageInfo, Paint, Rect, Surface};
use std::fs::File;
use std::io::Write;

fn main() {
    let mut surface = Surface::new_raster_n32_premul((100, 100)).unwrap();
    let canvas = surface.canvas();
    
    // Load the image using Image::from_encoded and create a canvas
    let bytes = include_bytes!("../assets/arena/Training.png");
    let data = Data::new_copy(bytes);
    let image = Image::from_encoded(data).unwrap();

    canvas.draw_image(&image, (0.0, 0.0), None);

    // Draw the image onto the canvas
    canvas.draw_image(&image, (0, 0), None);

    // Save the canvas content to a file
    let mut output_file = File::create("../tests.png").unwrap();
    match image.encode(None, EncodedImageFormat::PNG, 100) {
        Some(data) => {
            output_file.write_all(data.as_bytes()).unwrap();
        }
        None => {
            eprintln!("ERROR: failed to encode image as PNG.");
        }
    };
}
