/*
   SPDX-FileCopyrightText: 2020-2023 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "developertooldialog.h"
#include "developertoolwidget.h"
#include <KConfigGroup>
#include <KLocalizedString>
#include <KSharedConfig>
#include <KWindowConfig>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QWindow>

namespace
{
static const char myDeveloperToolDialogConfigGroupName[] = "DeveloperToolDialog";
}

using namespace WebEngineViewer;
DeveloperToolDialog::DeveloperToolDialog(QWidget *parent)
    : QDialog(parent)
    , mDeveloperToolWidget(new DeveloperToolWidget(this))
{
    setWindowTitle(i18nc("@title:window", "Developer Tool"));
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(QStringLiteral("mainLayout"));

    mDeveloperToolWidget->setObjectName(QStringLiteral("mDeveloperToolWidget"));
    mainLayout->addWidget(mDeveloperToolWidget);

    auto buttonBox = new QDialogButtonBox(QDialogButtonBox::Close, this);
    buttonBox->setObjectName(QStringLiteral("buttonBox"));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &DeveloperToolDialog::reject);
    connect(mDeveloperToolWidget, &DeveloperToolWidget::closeRequested, this, &DeveloperToolDialog::reject);
    mainLayout->addWidget(buttonBox);
    readConfig();
}

DeveloperToolDialog::~DeveloperToolDialog()
{
    writeConfig();
}

QWebEnginePage *DeveloperToolDialog::enginePage() const
{
    return mDeveloperToolWidget->enginePage();
}

void DeveloperToolDialog::readConfig()
{
    create(); // ensure a window is created
    windowHandle()->resize(QSize(800, 600));
    KConfigGroup group(KSharedConfig::openStateConfig(), QLatin1String(myDeveloperToolDialogConfigGroupName));
    KWindowConfig::restoreWindowSize(windowHandle(), group);
    resize(windowHandle()->size()); // workaround for QTBUG-40584
}

void DeveloperToolDialog::writeConfig()
{
    KConfigGroup group(KSharedConfig::openStateConfig(), QLatin1String(myDeveloperToolDialogConfigGroupName));
    KWindowConfig::saveWindowSize(windowHandle(), group);
}

#include "moc_developertooldialog.cpp"
