/*
  SPDX-FileCopyrightText: 2013-2022 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: LGPL-2.0-or-later

*/

#pragma once

#include <Akonadi/Attribute>
#include <memory>
namespace MessageViewer
{
class ScamAttributePrivate;

class ScamAttribute : public Akonadi::Attribute
{
public:
    explicit ScamAttribute();
    ~ScamAttribute() override;

    Q_REQUIRED_RESULT ScamAttribute *clone() const override;
    Q_REQUIRED_RESULT QByteArray type() const override;
    Q_REQUIRED_RESULT QByteArray serialized() const override;
    void deserialize(const QByteArray &data) override;

    Q_REQUIRED_RESULT bool isAScam() const;
    void setIsAScam(bool b);

    Q_REQUIRED_RESULT bool operator==(const ScamAttribute &other) const;

private:
    friend class ScamAttributePrivate;
    std::unique_ptr<ScamAttributePrivate> const d;
};
}

