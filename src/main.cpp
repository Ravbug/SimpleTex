#include <QApplication>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QFrame>
#include <QPdfDocument>
#include <QPdfView>
#include <Qsci/qsciscintilla.h>

extern "C" void init_pdftex_lib();

class MainWindow : public QMainWindow{
public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent){
        this->setGeometry(300, 300, 800, 400);
        this->setWindowTitle("SimpleTex");
        auto layout = new QHBoxLayout;
        auto editor = new QsciScintilla;
        editor->setText("hello");
        editor->setUtf8(true);
        layout->addWidget(editor);
        
        auto pdfView = new QPdfView;
        layout->addWidget(pdfView);
        
        auto frame = new QFrame();
        frame->setLayout(layout);
        
        this->setCentralWidget(frame);
    }
};

int main(int argc, char** argv){
    QApplication a(argc, argv);
        
    auto win = std::make_unique<MainWindow>();
    win->show();
    
    init_pdftex_lib();
    
    return a.exec();
}
