#include "vrthemedata.h"

VRThemeData::VRThemeData(VRSettings::Theme theme)
{
    changeTheme(theme);
}

void VRThemeData::changeTheme(VRSettings::Theme theme) {
    if (theme == VRSettings::Theme::DARK) {
        setAppBackgroundColor("#313537");
        setTabBackgroundColor("#3e4244");
        setTabInactiveColor("#555555");
        setAccentColor("#a7def9");
        setTextColor("#fff");
    } else if (theme == VRSettings::Theme::LIGHT) {
        setAppBackgroundColor("#fcfcfc");
        setTabBackgroundColor("#fff");
        setTabInactiveColor("#eee");
        setAccentColor("#0047ba");
        setTextColor("#333");
    } else {
        // Default to dark theme.
        setAppBackgroundColor("#313537");
        setTabBackgroundColor("#3e4244");
        setTabInactiveColor("#555555");
        setAccentColor("#a7def9");
        setTextColor("#fff");
    }

    emit themeChanged();
}

QString VRThemeData::getAppBackgroundColor() const
{
    return appBackgroundColor;
}

void VRThemeData::setAppBackgroundColor(const QString &value)
{
    appBackgroundColor = value;
    emit appBackgroundColorChanged();
}

QString VRThemeData::getTabBackgroundColor() const
{
    return tabBackgroundColor;
}

void VRThemeData::setTabBackgroundColor(const QString &value)
{
    tabBackgroundColor = value;
    emit tabBackgroundColorChanged();
}

QString VRThemeData::getTabInactiveColor() const
{
    return tabInactiveColor;
}

void VRThemeData::setTabInactiveColor(const QString &value)
{
    tabInactiveColor = value;
    emit tabInactiveColorChanged();
}

QString VRThemeData::getAccentColor() const
{
    return accentColor;
}

void VRThemeData::setAccentColor(const QString &value)
{
    accentColor = value;
    emit accentColorChanged();
}

QString VRThemeData::getTextColor() const
{
    return textColor;
}

void VRThemeData::setTextColor(const QString &value)
{
    textColor = value;
    emit textColorChanged();
}
