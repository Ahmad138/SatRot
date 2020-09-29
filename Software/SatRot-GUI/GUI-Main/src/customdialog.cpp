#include "../includes/customdialog.h"

CustomDialog::CustomDialog(const QStringList& items)
{

    box = new QComboBox;
    box->setEditable(true);
    box->addItems(items);

    auto hostLabel = new QLabel(tr("&Server name:"));
    hostLabel->setBuddy(box);

    QPushButton* connectButton = new QPushButton("Connect");
    auto quitButton = new QPushButton(tr("Quit"));

    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(connectButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    QGridLayout* mainLayout = nullptr;
    mainLayout = new QGridLayout(this);

    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(box, 0, 1);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);

    setWindowTitle("Connect to Server");

    connect(connectButton, &QPushButton::clicked, this, [this]()
    {
        accept();
    });
    connect(quitButton, &QPushButton::clicked, this, [this]()
    {
        reject();
    });
}
