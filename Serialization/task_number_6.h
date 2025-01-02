//
// Created by Oleksandr Demnychenko on 02.01.2025.
//

#include "task_number_5.h"
#include "vector"
#include "filesystem"

namespace fs = std::filesystem;
std::vector<std::string> get_images(fs::path const & dirpath)
{
    std::vector<std::string> paths;
    for(auto const& p : fs::directory_iterator(dirpath))
    {
        if(p.path().extension() == ".jpeg")
        {
            paths.push_back(p.path().string());
        }
    }
    return paths;
}

void print_pdf_images(fs::path const& pdfpath, fs::path const& dirpath)
{
    const int height = 842;
    const int width = 595;
    const int margin = 20;

    auto image_path = get_images(dirpath);
    PDFWriter pdf;
    pdf.StartPDF(pdfpath.string(), ePDFVersion13);
    PDFPage* page = nullptr;
    PageContentContext* context = nullptr;

    auto top = height - margin;
    for(size_t i = 0; i < image_path.size(); i++)
    {
        auto dims = pdf.GetImageDimensions(image_path[i]);
        if(i == 0 || top - dims.second < margin)
        {
            if(page != nullptr)
            {
                pdf.EndPageContentContext(context);
                pdf.WritePageAndRelease(page);
            }

            page = new PDFPage();
            page->SetMediaBox(PDFRectangle(0, 0, width, height));
            context = pdf.StartPageContentContext(page);
            top = height - margin;
        }

        context->DrawImage(margin, top - dims.second, image_path[i]);
        top -= dims.second + margin;
    }

    if(page != nullptr)
    {
        pdf.EndPageContentContext(context);
        pdf.WritePageAndRelease(page);
    }

    pdf.EndPDF();
}

static void task_number_6()
{
    print_pdf_images("../PracticeC/Serialization/test/movies_images.pdf", "../PracticeC/Serialization/res/");
}