#include <QApplication>
#include <QMainWindow>
#include <QSplitter>
#include <QTreeWidget>
#include <QPlainTextEdit>
#include <QTextBrowser>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Markdown Studio");
    window.resize(1200, 800);

    auto *splitter = new QSplitter(&window);
    auto *sidebar = new QTreeWidget();
    sidebar->setHeaderLabel("Documents");
    sidebar->addTopLevelItem(new QTreeWidgetItem({"Project Proposal.md"}));
    sidebar->addTopLevelItem(new QTreeWidgetItem({"Design Doc.md"}));
    sidebar->addTopLevelItem(new QTreeWidgetItem({"API Specification.md"}));

    auto *editor = new QPlainTextEdit();
    editor->setPlainText(
        "# Project Proposal\n\n"
        "## 1. Overview\n"
        "This document describes the project proposal for our markdown editor.\n\n"
        "## 2. Goals\n"
        "- Build a fast markdown editor\n"
        "- Realtime collaboration\n"
        "- Cloud sync and version history\n"
    );

    auto *preview = new QTextBrowser();
    preview->setHtml(
        "<h1>Project Proposal</h1>"
        "<h2>1. Overview</h2>"
        "<p>This document describes the project proposal for our markdown editor.</p>"
        "<h2>2. Goals</h2>"
        "<ul>"
        "<li>Build a fast markdown editor</li>"
        "<li>Realtime collaboration</li>"
        "<li>Cloud sync and version history</li>"
        "</ul>"
    );

    splitter->addWidget(sidebar);
    splitter->addWidget(editor);
    splitter->addWidget(preview);

    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 3);
    splitter->setStretchFactor(2, 3);

    window.setCentralWidget(splitter);
    window.show();

    return app.exec();
}