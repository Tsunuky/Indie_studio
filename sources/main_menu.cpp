/*
** EPITECH PROJECT, 2019
** testtexture
** File description:
** tes
*/
#include "Graph/lib.hpp"

void Mainenu::remove_button(IGUIButton **element)
{
    if (*element != nullptr) {
        (*element)->remove();
        *element = nullptr;
    }
}

void Mainenu::add_static_text(std::string name, const wchar_t *text, rect<s32> pos)
{
    static_text.emplace(name, (IGUIStaticText *)name.c_str());
    static_text[name] = _game->_graphicLibrary->getEnv()->addStaticText(text, pos);
}

void Mainenu::add_insert_text(std::string name, const wchar_t *text, rect<s32> pos)
{
    insert_text.emplace(name, (IGUIEditBox *)name.c_str());
    insert_text[name] = _game->_graphicLibrary->getEnv()->addEditBox(text, pos);
    insert_text[name]->setOverrideColor({255, 27, 27, 27});
    insert_text[name]->setVisible(false);
}

void Mainenu::setImageButton()
{
    std::vector<std::string> butt_adresse {"new_game", "continue", "multi", "option", "quit", "back_new_game", "back_continue", "back_option", "back_multi", "next_map", "prev_map", "add_bot1", "add_bot2", "add_bot3", "add_bot4", "add_player1", "add_player2", "disable1", "disable2", "disable3", "disable4", "host", "connect", "next_diff1", "prev_diff1", "prev_diff2", "next_diff2", "next_dif3", "prev_diff3", "next_dif4", "prev_diff4", "start", "next_load", "prev_load", "save_name", "load"};
    std::vector<rect<s32>> pos {{0, 200, 320, 260}, {0, 260, 320, 320}, {0, 320, 320, 380}, {0, 380, 320, 440}, {0, 440, 320, 500}};
    std::vector<std::wstring> butt_name {L"New game", L"Continue", L"Multiplayer", L"Option", L"Quit"};
    std::vector<std::wstring> butt_tips {L"Create new game", L"Continue a game", L"Lunch a multiplayer party", L"Game option", L"Exits Program"};

    for (size_t i = 0; i < butt_adresse.size(); i++) {
        if (i < 5) {
            buttons.emplace(butt_adresse[i], (IGUIButton *)butt_name[i].c_str());
            draw_button(&buttons[butt_adresse[i]], pos[i], butt_name[i].c_str(), butt_tips[i].c_str(), 1);
        } else {
            buttons.emplace(butt_adresse[i], (IGUIButton *)butt_name[i].c_str());
            buttons[butt_adresse[i]] = nullptr;
        }
    }
}

void Mainenu::draw_menu()
{
    if (in_menu != 5) {
        _game->_graphicLibrary->getDriver()->draw2DImage(sprite["BACKGROUND"], core::position2d<s32>(0, 0), {0,0,1920,1080}, 0, {255,255,255,255}, true);
        _game->_graphicLibrary->getDriver()->draw2DRectangle({180, 27, 27, 27}, {0, 0, 320, 1080});
    }
}

void Mainenu::draw_button(IGUIButton **element, rect<s32> rect, const wchar_t *display, const wchar_t *tips, int transp)
{
    *element = _game->_graphicLibrary->getEnv()->addButton(rect, 0, -1 , display, tips);
    if (transp == 1) {
        (*element)->setUseAlphaChannel(true);
        (*element)->setDrawBorder(0);
        (*element)->setImage(sprite["VISIBLE"]);
    }
}

void Mainenu::draw_menu_option()
{
    if (in_menu == -3) {
        _game->_graphicLibrary->getDriver()->draw2DRectangle({240, 25, 25, 25}, _rect[0]);
        if (_rect[0].UpperLeftCorner.X < 1920)
            _rect[0].operator += (vector2di(10, 0));
        else
            in_menu = 0;
    } else {
        in_menu = 3;
        if (buttons["back_option"] == nullptr)
            draw_button(&buttons["back_option"], {220, 380, 380, 440}, L"<", L"Back to the menu", 1);
        _game->_graphicLibrary->getDriver()->draw2DRectangle({30, 120, 120, 120}, {0, 380 , 320, 440});
        _game->_graphicLibrary->getDriver()->draw2DRectangle({240, 25, 25, 25}, _rect[0]);
        if (_rect[0].UpperLeftCorner.X > 320)
            _rect[0].operator -= (vector2di(10, 0));
    }
}

void Mainenu::Button_pressed()
{
    if (buttons["quit"]->isPressed()) {
        _game->_graphicLibrary->getDivice()->closeDevice();
        exit(56);
    }

    std::vector<std::string> butt {"back_new_game", "back_continue", "back_option", "back_multi"};
    for (size_t i = 0; i < 4; ++i) {
        if (buttons[butt[i]] && buttons[butt[i]]->isPressed()) {
            in_menu = (i+1) *- 1;
            remove_button(&buttons[butt[i]]);
        }
    }
    if ((buttons["new_game"]->isPressed() && in_menu == 0) ||(in_menu == 1 || in_menu == -1))
        draw_menu_new();
    if ((buttons["continue"]->isPressed() && in_menu == 0) || in_menu == 2 || in_menu == -2)
        draw_menu_continu();
    if ((buttons["multi"]->isPressed() && in_menu == 0) || in_menu == 4 || in_menu == -4)
        draw_menu_multi();
    if ((buttons["option"]->isPressed() && in_menu == 0) || in_menu == 3 || in_menu == -3)
        draw_menu_option();
}

void Mainenu::clear_all_menu()
{
    in_menu = 5;
    clear_all_player();
    for (size_t i = 0; i < _rect.size(); ++i)
        _rect[i].operator += ({1600, 0});
    for (size_t i = 0; i < _player.size(); ++i)
        _player[i].operator += ({1600, 0});
    for (size_t i = 0; i < _pdp.size(); ++i)
        _pdp[i].operator += ({1600, 0});
    remove_button(&buttons["next_map"]);
    remove_button(&buttons["prev_map"]);
    remove_button(&buttons["add_bot1"]);
    remove_button(&buttons["add_bot2"]);
    remove_button(&buttons["add_bot3"]);
    remove_button(&buttons["add_bot4"]);
    remove_button(&buttons["add_player1"]);
    remove_button(&buttons["add_player2"]);
    remove_button(&buttons["start"]);
    remove_button(&buttons["back_new_game"]);
    remove_button(&buttons["back_continue"]);
    remove_button(&buttons["back_option"]);
    remove_button(&buttons["back_multi"]);
    buttons["new_game"]->setVisible(false);
    buttons["continue"]->setVisible(false);
    buttons["multi"]->setVisible(false);
    buttons["option"]->setVisible(false);
    buttons["quit"]->setVisible(false);
}

