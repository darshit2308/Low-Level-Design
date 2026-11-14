#include <bits/stdc++.h>
// #include <fstream>

using namespace std;

class DocumentEditor
{
private:
    vector<string> documentElements;
    string renderedDocument; // we save the rendered document, in order to save the re-render.
    bool isDirty = false;    // To track, if document is changed after the last rendering

public:
    // adds the text as plain text
    void addText(string text)
    {
        documentElements.push_back(text);
        isDirty = true;
    }
    // adds an image represented by its file path
    void addImage(string imagePath)
    {
        documentElements.push_back(imagePath);
        isDirty = true;
    }
    // Renders the document by checking the type of each element at runtime
    string renderDocument()
    {
        if (isDirty)
        {
            renderedDocument.clear();

            for (const string &element : documentElements)
            { // We could had directly added the elements, but we want to segregatae the images and text
                // renderedDocument += element;
                if (element.size() >= 5 &&
                    (element.substr(element.size() - 5) == ".jpeg" ||
                     element.substr(element.size() - 4) == ".png"))
                {

                    renderedDocument += "[Image : " + element + " ]\n";
                }
                else
                {
                    renderedDocument += element + "\n";
                }
            }

            isDirty = false;
        }
        return renderedDocument;
    }
    void saveToFile()
    {
        ofstream file("document.txt"); // create an empty file, document.txt is the destination
        if(file.is_open()){ // 'file' is not the actual file, but the object which provides the interface to interact with the file.
            file << renderDocument(); // put the rendered document inside the file.
            file.close();
            cout << "Document saved to document.txt" << endl;
        } else {// We cannot write on file, if it is not open
            cout << "Unable to open file for writting" << endl;
        }
    }
};

int main(){
    DocumentEditor editor;
    editor.addText("Hello World");
    editor.addImage("picture.jpg");
    editor.addText("This is a document editor");

    cout << editor.renderDocument() << endl;
    editor.saveToFile();
}