#include <calibration/Calibrator.hpp>
#include "cmdline.h"
using namespace SLS;
int main(int argc, char** argv)
{
    cmdline::parser p;
    p.add<std::string>("images", 'i', "Folder contains images for calibration", true);
    p.add<std::string>("output", 'o', "Output of calibration file", true);
    p.parse_check(argc, argv);

    ImageFileProcessor cam("calibCam");

    // Calibrator takes a camera as input and output camera configuration.
    Calibrator::Calibrate(&cam, p.get<std::string>("images"), p.get<std::string>("output"));
    return 0;
}
