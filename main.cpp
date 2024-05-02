#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <tesseract/renderer.h>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    // Ensure there are files to process
    if (argc < 2) {
        std::cout << "At least one image file arg required." << std::endl;
        return -1;
    }

    // Create a Tesseract instance
    tesseract::TessBaseAPI api;

    // Initialize tesseract-ocr with English, without specifying tessdata path using the LSTM OCR engine mode
    if (api.Init(nullptr, "eng", tesseract::OEM_LSTM_ONLY) != 0) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        return -1;
    }

    // Process the input files
    for (int i = 1; i < argc; i++) {
        std::string input_filename(argv[i]);
        std::string output_filename = input_filename.substr(0, input_filename.find_last_of("."));

        // Create an outputter
        tesseract::TessTextRenderer text_renderer(output_filename.c_str());

        // Run OCR on the input image
        bool success = api.ProcessPages(input_filename.c_str(), nullptr, 0, &text_renderer);

        // Check if it's successful
        if (!success) {
            fprintf(stderr, "Failed processing file.\n");
        }
    }

    return 0;
}
