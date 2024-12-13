// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtWidgets>

void applyDarkMode(QWidget *window) {
    QString darkStyle = R"(
        QWidget {
            background-color: #121212;
            color: #FFFFFF;
        }
        QPushButton {
            background-color: #1E1E1E;
            color: #FFFFFF;
            border: 1px solid #333333;
            border-radius: 5px;
            padding: 5px;
        }
        QPushButton:hover {
            background-color: #333333;
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
        QPushButton {
            background-color: #E0E0E0;
            color: #000000;
            border: 1px solid #CCCCCC;
            border-radius: 5px;
            padding: 5px;
        }
        QPushButton:hover {
            background-color: #DDDDDD;
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
    QPushButton *switchButton = new QPushButton("Switch to Dark Mode");
    switchButton->setFixedSize(400, 90);

    // Create a layout
    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(switchButton, 0, Qt::AlignCenter);

    // Apply light mode by default
    applyLightMode(&window);

    // Connect the button to toggle between modes
    QObject::connect(switchButton, &QPushButton::clicked, [&window, switchButton]() {
        static bool darkMode = false;
        if (darkMode) {
            applyLightMode(&window);
            switchButton->setText("Switch to Dark Mode");
        } else {
            applyDarkMode(&window);
            switchButton->setText("Switch to Light Mode");
        }
        darkMode = !darkMode;
    });

    window.show();
    return app.exec();
}
