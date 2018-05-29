#include <QString>
#include <QtTest>
#include "../VRMain/vrsettings.h"
#include "../VRMain/view/vrthemedata.h"

class VRTest : public QObject
{
    Q_OBJECT

public:
    VRTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    // Initialization tests.
    void settings_Initialization_Unit();
    void settings_Initialization_Lang();
    void settings_Initialization_Theme();

    // Parsing tests.
    void settings_Parsing_Unit();
    void settings_Parsing_Lang();
    void settings_Parsing_Theme();

    // String conversion tests.
    void settings_StringConversion_Unit();
    void settings_StringConversion_Lang();
    void settings_StringConversion_Theme();

    // ThemeData tests.
    void themeData_Initialization();
    void themeData_ChangeTheme_Light();
    void themeData_ChangeTheme_Dark();
    void themeData_ChangeTheme_Invalid();

private:
    VRSettings* settings;
    VRThemeData* theme;
};

VRTest::VRTest()
{
    this->settings = nullptr;
    this->theme = nullptr;
}

void VRTest::initTestCase()
{
    theme = new VRThemeData(VRSettings::Theme::DARK);
}

void VRTest::cleanupTestCase()
{
    delete theme;
}

void VRTest::init()
{
    settings = new VRSettings();
}

void VRTest::cleanup()
{
    delete settings;
}

//
// VRSettings
//

// Initialization tests.
void VRTest::settings_Initialization_Unit()
{
    QVERIFY2(settings->getUnit() == VRSettings::Unit::METRIC, "Wrong default unit system after initialization.");
}

void VRTest::settings_Initialization_Lang()
{
    QVERIFY2(settings->getLang() == VRSettings::Language::ENGLISH, "Wrong default language after initialization.");
}

void VRTest::settings_Initialization_Theme()
{
    QVERIFY2(settings->getTheme() == VRSettings::Theme::DARK, "Wrong default theme after initialization.");
}

// Parsing tests.
void VRTest::settings_Parsing_Unit()
{
    QVERIFY2(VRSettings::parseUnit("metric") == VRSettings::Unit::METRIC, "'metric' has not been parsed to VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("METRIC") == VRSettings::Unit::METRIC, "'METRIC' has not been parsed to VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("meTriC") == VRSettings::Unit::METRIC, "'meTriC' has not been parsed to VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("VisualRacing") == VRSettings::Unit::METRIC, "Parsing 'VisualRacing' did not result in default VRSettings::Unit::METRIC.");
    QVERIFY2(VRSettings::parseUnit("imperial") == VRSettings::Unit::IMPERIAL, "'imperial' has not been parsed to VRSettings::Unit::IMPERIAL.");
}

void VRTest::settings_Parsing_Lang()
{
    QVERIFY2(VRSettings::parseLanguage("en") == VRSettings::Language::ENGLISH, "'en' has not been parsed to VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("EN") == VRSettings::Language::ENGLISH, "'EN' has not been parsed to VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("En") == VRSettings::Language::ENGLISH, "'En' has not been parsed to VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("VisualRacing") == VRSettings::Language::ENGLISH, "Parsing 'VisualRacing' did not result in default VRSettings::Language::ENGLISH.");
    QVERIFY2(VRSettings::parseLanguage("de") == VRSettings::Language::GERMAN, "'de' has not been parsed to VRSettings::Language::GERMAN.");
}

void VRTest::settings_Parsing_Theme()
{
    QVERIFY2(VRSettings::parseTheme("dark") == VRSettings::Theme::DARK, "'dark' has not been parsed to VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("DARK") == VRSettings::Theme::DARK, "'DARK' has not been parsed to VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("daRk") == VRSettings::Theme::DARK, "'daRk' has not been parsed to VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("VisualRacing") == VRSettings::Theme::DARK, "Parsing 'VisualRacing' did not result in default VRSettings::Theme::DARK.");
    QVERIFY2(VRSettings::parseTheme("light") == VRSettings::Theme::LIGHT, "'light' has not been parsed to VRSettings::Theme::LIGHT.");
}

// String conversion tests.
void VRTest::settings_StringConversion_Unit()
{
    settings->setUnit(VRSettings::Unit::IMPERIAL);
    QVERIFY2(settings->unitAsString() == "unit:imperial", "unitAsString for imperial unit system returned a wrong result.");
    settings->setUnit(VRSettings::Unit::METRIC);
    QVERIFY2(settings->unitAsString() == "unit:metric", "unitAsString for metric unit system returned a wrong result.");
}

void VRTest::settings_StringConversion_Lang()
{
    settings->setLang(VRSettings::Language::GERMAN);
    QVERIFY2(settings->languageAsString() == "lang:de", "languageAsString for german language returned a wrong result.");
    settings->setLang(VRSettings::Language::ENGLISH);
    QVERIFY2(settings->languageAsString() == "lang:en", "languageAsString for english language returned a wrong result.");
}

void VRTest::settings_StringConversion_Theme()
{
    settings->setTheme(VRSettings::Theme::LIGHT);
    QVERIFY2(settings->themeAsString() == "theme:light", "themeAsString for light theme returned a wrong result.");
    settings->setTheme(VRSettings::Theme::DARK);
    QVERIFY2(settings->themeAsString() == "theme:dark", "themeAsString for dark theme returned a wrong result.");
}

//
// VRThemeData
//

void VRTest::themeData_Initialization()
{
    VRThemeData dark(VRSettings::Theme::DARK);
    QVERIFY2(dark.getAppBackgroundColor() == "#313537", "Wrong app-background-color after initializing with dark theme.");
    QVERIFY2(dark.getTabBackgroundColor() == "#3e4244", "Wrong tab-background-color after initializing with dark theme.");
    QVERIFY2(dark.getTabInactiveColor() == "#555555", "Wrong tab-inactive-color after initializing with dark theme.");
    QVERIFY2(dark.getAccentColor() == "#a7def9", "Wrong accent-color after initializing with dark theme.");
    QVERIFY2(dark.getTextColor() == "#fff", "Wrong text color after initializing with dark theme.");

    VRThemeData light(VRSettings::Theme::LIGHT);
    QVERIFY2(light.getAppBackgroundColor() == "#fcfcfc", "Wrong app-background-color after initializing with light theme.");
    QVERIFY2(light.getTabBackgroundColor() == "#fff", "Wrong tab-background-color after initializing with light theme.");
    QVERIFY2(light.getTabInactiveColor() == "#eee", "Wrong tab-inactive-color after initializing with light theme.");
    QVERIFY2(light.getAccentColor() == "#0047ba", "Wrong accent-color after initializing with light theme.");
    QVERIFY2(light.getTextColor() == "#333", "Wrong text color after initializing with light theme.");
}

void VRTest::themeData_ChangeTheme_Light()
{
    theme->changeTheme(VRSettings::Theme::LIGHT);
    QVERIFY2(theme->getAppBackgroundColor() == "#fcfcfc", "Wrong app-background-color after changing theme to light theme.");
    QVERIFY2(theme->getTabBackgroundColor() == "#fff", "Wrong tab-background-color after changing theme to light theme.");
    QVERIFY2(theme->getTabInactiveColor() == "#eee", "Wrong tab-inactive-color after changing theme to light theme.");
    QVERIFY2(theme->getAccentColor() == "#0047ba", "Wrong accent-color after changing theme to light theme.");
    QVERIFY2(theme->getTextColor() == "#333", "Wrong text color after changing theme to light theme.");
}

void VRTest::themeData_ChangeTheme_Dark()
{
    theme->changeTheme(VRSettings::Theme::DARK);
    QVERIFY2(theme->getAppBackgroundColor() == "#313537", "Wrong app-background-color after changing theme to dark theme.");
    QVERIFY2(theme->getTabBackgroundColor() == "#3e4244", "Wrong tab-background-color after changing theme to dark theme.");
    QVERIFY2(theme->getTabInactiveColor() == "#555555", "Wrong tab-inactive-color after changing theme to dark theme.");
    QVERIFY2(theme->getAccentColor() == "#a7def9", "Wrong accent-color after changing theme to dark theme.");
    QVERIFY2(theme->getTextColor() == "#fff", "Wrong text color after changing theme to dark theme.");
}

void VRTest::themeData_ChangeTheme_Invalid()
{
    theme->changeTheme(static_cast<VRSettings::Theme>(-100));
    QVERIFY2(theme->getAppBackgroundColor() == "#313537", "Did not default to dark app-background-color after changing theme to invalid value.");
    QVERIFY2(theme->getTabBackgroundColor() == "#3e4244", "Did not default to dark tab-background-color after changing theme to invalid value.");
    QVERIFY2(theme->getTabInactiveColor() == "#555555", "Did not default to dark tab-inactive-color after changing theme to invalid value.");
    QVERIFY2(theme->getAccentColor() == "#a7def9", "Did not default to dark accent-color after changing theme to invalid value.");
    QVERIFY2(theme->getTextColor() == "#fff", "Did not default to dark text color after changing theme to invalid value.");
}

//
// Execute tests.
//
QTEST_APPLESS_MAIN(VRTest)

#include "tst_vrtest.moc"
