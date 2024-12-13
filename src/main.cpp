#include <QtWidgets>
#include <QTextBlock>

class LineNumberArea : public QWidget {
public:
    LineNumberArea(QTextEdit *editor) : QWidget(editor), textEdit(editor) {}

    QSize sizeHint() const override {
        return QSize(textEdit->document()->documentLayout()->documentSize().width(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setPen(Qt::gray);

        QTextBlock block = textEdit->document()->begin();
        int blockNumber = 1;
        while (block.isValid()) {
            QRectF rect = textEdit->document()->documentLayout()->blockBoundingRect(block);
            painter.drawText(0, rect.top(), width(), rect.height(), Qt::AlignRight, QString::number(blockNumber));
            block = block.next();
            ++blockNumber;
        }
    }

private:
    QTextEdit *textEdit;
};

class EditorWithLineNumbers : public QWidget {
public:
    EditorWithLineNumbers(QWidget *parent = nullptr) : QWidget(parent) {
        textEdit = new QTextEdit(this);
        textEdit->setPlaceholderText("Write your code here...");

        lineNumberArea = new LineNumberArea(textEdit);

        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->setSpacing(0);
        layout->addWidget(lineNumberArea);
        layout->addWidget(textEdit);
        setLayout(layout);

        connect(textEdit, &QTextEdit::textChanged, this, &EditorWithLineNumbers::updateLineNumberArea);
        connect(textEdit->verticalScrollBar(), &QScrollBar::valueChanged, this, &EditorWithLineNumbers::updateLineNumberArea);
    }

    void updateLineNumberArea() {
        lineNumberArea->update();
    }

    QTextEdit* getTextEdit() const {
        return textEdit;
    }

private:
    QTextEdit *textEdit;
    LineNumberArea *lineNumberArea;
};

void applyDarkMode(QWidget *window) {
    QString darkStyle = R"(
        QWidget {
            background-color: #121212;
            color: #FFFFFF;
        }
    )";
    window->setStyleSheet(darkStyle);
}

void applyLightMode(QWidget *window) {
    QString lightStyle = R"(
        QWidget {
            background-color: #FFFFFF;
            color: #000000;
        }
    )";
    window->setStyleSheet(lightStyle);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.resize(1440, 900);
    window.setWindowTitle(QApplication::translate("Ivory", "Ivory"));

    // Create the toggle button
    QCheckBox *toggleButton = new QCheckBox("Dark Mode");
    toggleButton->setStyleSheet(R"(
        QCheckBox {
            spacing: 10px;
        }
        QCheckBox::indicator {
            width: 40px;
            height: 20px;
            border-radius: 10px;
            background: #E0E0E0;
            border: 1px solid #CCCCCC;
        }
        QCheckBox::indicator:checked {
            background: #333333;
            border: 1px solid #666666;
        }
        QCheckBox::indicator:checked:hover {
            background: #444444;
        }
        QCheckBox::indicator:hover {
            background: #DDDDDD;
        }
    )");

    // Create the compile and run button
    QPushButton *compileButton = new QPushButton("Compile & Run");
    compileButton->setFixedSize(150, 40);

    // Create the editor with line numbers
    EditorWithLineNumbers *editorWithLineNumbers = new EditorWithLineNumbers();

    // Create the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(&window);

    // Create a top bar layout for the compile and run button and the toggle button
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(compileButton);
    topLayout->addStretch();
    topLayout->addWidget(toggleButton);

    // Add the top bar to the main layout
    mainLayout->addLayout(topLayout);

    // Create a horizontal splitter to divide the editor (left) and game screen (right)
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->setHandleWidth(1);

    // Create a dummy QWidget for the right side (game screen placeholder)
    QWidget *gameScreen = new QWidget();
    gameScreen->setStyleSheet("background-color: #f0f0f0;");

    // Add the text editor and game screen to the splitter
    splitter->addWidget(editorWithLineNumbers);
    splitter->addWidget(gameScreen);

    // Add the splitter to the main layout
    mainLayout->addWidget(splitter);

    // Apply light mode by default
    applyLightMode(&window);

    // Connect the toggle button to switch modes
    QObject::connect(toggleButton, &QCheckBox::toggled, [&window](bool checked) {
        if (checked) {
            applyDarkMode(&window);
        } else {
            applyLightMode(&window);
        }
    });

    // Connect the compile button (for now, it will just print to the console)
    QObject::connect(compileButton, &QPushButton::clicked, [&]() {
        QString code = editorWithLineNumbers->getTextEdit()->toPlainText();
        // You can add logic here to compile and run code.
        // For example, executing a shell command or running a program.
        qDebug() << "Compiling and running code:\n" << code;
        // Dummy logic: Print the code content (you can replace this with actual compile/run logic)
        QTextStream(stdout) << "Running the following code:\n" << code;
    });

    window.show();
    return app.exec();
}
