#include <bits/stdc++.h>
// #include <fstream>

using namespace std;

class DocumentElement {
public: 
    virtual string render() = 0;
};

// implementation for text element
class TextElement : public DocumentElement {
private: 
    string text;
public: 
    TextElement(string text){
        this->text = text;
    }
    string render() override {
        return text;
    }
};


// implementation for image element
class ImageElement : public DocumentElement {
private: 
    string imagePath;
public: 
    ImageElement(string imagePath) {
        this->imagePath = imagePath;
    }
    string render() override {
        return "[Image: ] " + imagePath + "]";
    } 
};

class NewLineElement: public DocumentElement {
public: 
    string render() override {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement{
public: 
    string render() override {
        return "\t";
    }
};

class Document{

private:
    vector<DocumentElement*> documentElements;

public: 
    void addElement(DocumentElement* element){
        documentElements.push_back(element);
    }

    string render() {
        string result;
        for(auto element: documentElements ){
            result += element->render(); // we call the render method of element object, either text or image
        }
        return result;
    }
};


class Persistence{
public: 
    virtual void save(string data) = 0;
};

// File storage implementation of persistence
class FileStorage : public Persistence {
public: 
    void save(string data) override {
        ofstream outFile("document.txt");
        if(outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing " << endl;
        }
    }
};

// DB storage implementation of persistence

class DBStorage : public Persistence {
public: 
    void save(string data) override {
        // save to DB
    }
};

class DocumentEditor
{
private:
    Document* document;
    Persistence* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Persistence* storage){
        this->document = document;
        this->storage = storage; 
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    void addTabSpace(){
        document->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument(){
        storage->save(renderDocument());
    }
    
};

int main(){
    Document* document = new Document();
    Persistence* persistence = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    return 0;
}