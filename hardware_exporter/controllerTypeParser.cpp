#include "controllerTypeParser.h"


std::string controllerTypeParser::parseControllerType(const std::string input)
{
    std::regex hp_regex("Hewlett-Packard", std::regex::icase);
    std::regex lsi_regex("LSI", std::regex::icase);
    std::regex adaptec_regex("Adaptec", std::regex::icase);

    if (std::regex_search(input, hp_regex)) {
        return "HP";
    }
    else if (std::regex_search(input, lsi_regex)) {
        return "LSI";
    }
    else if (std::regex_search(input, adaptec_regex)) {
        return "Adaptec";
    }
    else {
        return "Unknown";
    }
}

std::string controllerTypeParser::getControllerType()
{
#ifdef NDEBUG
    std::string infoOutput;

    try {
        infoOutput = runCommand("lspci | egrep 'RAID|SCSI' | egrep -i 'Hewlett-Packard|LSI|Adaptec' 2> /dev/null");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error executing the command, trying with sudo: " << e.what() << std::endl;
        try {
            infoOutput = runCommandWithSudo("lspci | egrep 'RAID|SCSI' | egrep -i 'Hewlett-Packard|LSI|Adaptec' 2> /dev/null");
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error executing the command with sudo: " << e.what() << std::endl;
        }
    }

    return parseControllerType(infoOutput);
#else
    std::string result = parseControllerType("05:00.0 RAID bus controller: LSI Logic / Symbios Logic MegaRAID SAS-3 3108 [Invader] (rev 02)");
    std::cout << "Type controller:\n" << result << std::endl;

    return "debug";
#endif
}
