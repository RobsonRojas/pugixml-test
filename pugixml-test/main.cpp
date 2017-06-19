#include "../pugixml-1.8/src/pugixml.hpp"

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    pugi::xml_document doc;

    // get a test document
    doc.load_string("<project> \
                    <name>test</name>\
                    <version>1.1</version>\
                    <public>yes</public>\
                    </project>");

    pugi::xml_node project = doc.child("project");

    // tag access[]
    std::cout << "Project name: " << project.child("name").text().get() << std::endl;
    std::cout << "Project version: " << project.child("version").text().as_double() << std::endl;
    std::cout << "Project visibility: " << project.child("public").text().as_bool() << std::endl;
    std::cout << "Project description: " << project.child("description").text().get() << std::endl;
    // end access[]

    std::cout << std::endl;

    // tag:: modify[]
    // change project version
    project.child("version").text() = 1.2;

    // add description element and set the contents
    // note that we do not have to explicitly add the node_pcdata child
    project.append_child("description").text().set("a test project");
    // end::modify[]

    //doc.save(std::cout);

    // saving to file
    std::cout << "Saving result: " << doc.save_file("test1.xml") << std::endl;

    return 0;
}
