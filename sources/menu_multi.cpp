/*
** EPITECH PROJECT, 2019
** testtexture
** File description:
** tes
*/
#include "Graph/lib.hpp"

int choice = 0;

void Mainenu::draw_multi_element()
{
    _game->_graphicLibrary->getDriver()->draw2DRectangle({240, 27, 27, 27}, _multirect[0]);
}

void Mainenu::comming_rect_multi()
{
    if (_multirect[0].UpperLeftCorner.Y <= 700)
        return;
    for (size_t i= 0; i < _multirect.size(); ++i)
        _multirect[i].operator -= ({0, 10});
    remove_button(&buttons["host"]);
    remove_button(&buttons["connect"]);
    if (!buttons["host"]) {
        draw_button(&buttons["host"], _multirect[1], L"Hostting", L"Host a party", 1);
        draw_button(&buttons["connect"], _multirect[2], L"Connect", L"Connect to a party", 1);
    }
}

void Mainenu::escape_rect_multi()
{
    if (_multirect[0].UpperLeftCorner.Y >= 1480) {
        if (choice == 0 || choice == 2)
            in_menu = 0;
        return;
    }
    for (size_t i= 0; i < _multirect.size(); ++i)
            _multirect[i].operator += ({0, 10});
    remove_button(&buttons["host"]);
    remove_button(&buttons["connect"]);
    if (!buttons["host"]) {
        draw_button(&buttons["host"], _multirect[1], L"Hostting", L"Host a party", 1);
        draw_button(&buttons["connect"], _multirect[2], L"Connect", L"Connect to a party", 1);
    }
}

void Mainenu::choice_pressed()
{
    std::wstring tmp;

    if (buttons["host"] && buttons["host"]->isPressed() && choice == 0)
        choice = 1;
    if (buttons["connect"] && buttons["connect"]->isPressed() && choice == 0) {
        choice = 2;
        if (insert_text["ip"] == nullptr) {
            add_insert_text("ip", L"insert an ip", {1000, 760, 1200, 790});
            insert_text["ip"]->setVisible(true);
        }
    }
    if (in_menu == -4 && insert_text["ip"] != nullptr) {
        insert_text["ip"]->remove();
        insert_text["ip"] = nullptr;
    }
    if (insert_text["ip"]) {
        tmp = (std::wstring)insert_text["ip"]->getText();
        std::string ip_temp(tmp.begin(), tmp.end());
        ip = ip_temp;
    }
}

void Mainenu::draw_menu_multi()
{
    choice_pressed();
    if (in_menu == 0)
            choice = 0;
    if (in_menu == -4) {
        escape_rect_multi();
        draw_multi_element();
        if (choice == 1) {
            draw_element();
            escape_rect();
            clear_all_player();
        }
    } else {
        in_menu = 4;
        if (buttons["back_multi"] == nullptr)
            draw_button(&buttons["back_multi"], {220, 320, 320, 380}, L"<", L"Back to the menu", 1);
        _game->_graphicLibrary->getDriver()->draw2DRectangle({30, 120, 120, 120}, {0, 320 , 320, 380});
        draw_multi_element();
        comming_rect_multi();
        if (choice == 1) {
            draw_element();
            comming_rect();
            player_bot_draw();
            next_prev_map_pressed();
            clear_player();
        }
    }
}
