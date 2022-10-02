#include <QApplication>
#include <QPushButton>
#include <Qsci/qsciscintilla.h>

int main(int argc, char** argv){
    QApplication a(argc, argv);

    //QPushButton button ("Hello world!");
    //button.show();
    
    QsciScintilla editor;
    editor.setText("hello");
    
    editor.show();

    return a.exec();
}
