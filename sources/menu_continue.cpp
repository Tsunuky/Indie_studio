/*
** EPITECH PROJECT, 2019
** testtexture
** File description:
** tes
*/

#include "Graph/lib.hpp"

int pos = 0;
int draw = 1;

void Mainenu::comming_rect_cont()
{
    if (_rect[0].UpperLeftCorner.X <= 320) {
        return;
    }
    for (size_t i = 0; i < _cont.size(); ++i)
        _cont[i].operator -= ({10, 0});
    _rect[0].operator -= (vector2di(10, 0));
    remove_button(&buttons["next_load"]);
    remove_button(&buttons["prev_load"]);
    remove_button(&buttons["load"]);
    if (!buttons["load"]) {
        draw_button(&buttons["next_load"], _cont[1], L">", L"next save file", 1);
        draw_button(&buttons["prev_load"], _cont[0], L"<", L"previous save file", 1);
        draw_button(&buttons["load"], _cont[2], L"Load", L"load the save file", 1);
    }
}

void Mainenu::escape_rect_cont()
{
    if (_rect[0].UpperLeftCorner.X >= 1920) {
        in_menu = 0;
        return;
    }
    for (size_t i = 0; i < _cont.size(); ++i)
        _cont[i].operator += ({10, 0});
    _rect[0].operator += (vector2di(10, 0));
    buttons["next_load"]->setVisible(false);
    buttons["prev_load"]->setVisible(false);
    buttons["load"]->setVisible(false);
    remove_button(&buttons["next_load"]);
    remove_button(&buttons["prev_load"]);
    remove_button(&buttons["load"]);
    if (!buttons["load"]) {
        draw_button(&buttons["next_load"], _cont[1], L">", L"next save file", 1);
        draw_button(&buttons["prev_load"], _cont[0], L"<", L"previous save file", 1);
        draw_button(&buttons["load"], _cont[2], L"Load", L"load the save file", 1);
    }
}

void Mainenu::draw_element_cont()
{
    _game->_graphicLibrary->getDriver()->draw2DRectangle({240, 25, 25, 25}, _rect[0]);
    _game->_graphicLibrary->getDriver()->draw2DRectangle({240, 180, 0, 180}, _cont[3]);
    if (save[pos] && _rect[0].UpperLeftCorner.X <= 320 && draw == 1) {
        draw = 0;
        save[pos]->setVisible(true);
    }
}

void Mainenu::cont_pressed()
{
    if (buttons["load"] && buttons["load"]->isPressed()) {
        // load le file
    }
    if (buttons["next_load"] && buttons["next_load"]->isPressed()) {
        buttons["next_load"]->setPressed(false);
        save[pos]->setVisible(false);
        draw = 1;
        pos += 1;
        if (pos > save.size())
            pos = 0;
        if (pos < 0)
            pos = save.size();
    }
    if (buttons["prev_load"] && buttons["prev_load"]->isPressed()) {
        buttons["prev_load"]->setPressed(false);
        save[pos]->setVisible(false);
        draw = 1;
        pos -= 1;
        if (pos < 0)
            pos = save.size();
        if (pos > save.size()) // change save.size par ton vector
            pos = 0;
    }
}

void Mainenu::draw_save()
{
	std::vector<std::wstring> name {L"pd", L"plop", L"lol"}; // remplace le vector par le tien

    for (size_t i = 0; i != save.size(); ++i) {
        save[i] = _game->_graphicLibrary->getEnv()->addStaticText(name[i].c_str(), _cont[4]);
        save[i]->setVisible(false);
    }
}

void Mainenu::clear_cont()
{
    if (save[pos]) {
        save[pos]->setVisible(false);
        save[pos] = nullptr;
    }
}

void Mainenu::draw_menu_continu()
{
    if (in_menu == -2) {
        draw_element_cont();
        escape_rect_cont();
        clear_cont();
    } else {
	    try {
		music.stop();
		if (!gameMusic.openFromFile("media/GameMusic.ogg"))
    			throw std::runtime_error("Could not load music");
    		gameMusic.setLoop(true);
    		gameMusic.play();
                Initializor init;
                Core core(dynamic_cast<LibContainer *>(_game), init.Game());
                core.launcher(0, 0, 0, "./../save/bomberman.save");
		gameMusic.stop();
	    }
            catch (std::exception err) {
                err.what();
                return;
            } catch (...) {
                return;
            }
        // in_menu = 2;
        // if (buttons["back_continue"] == nullptr)
        //     draw_button(&buttons["back_continue"], {220, 260, 320, 320}, L"<", L"Back to the menu", 1);
        // _game->_graphicLibrary->getDriver()->draw2DRectangle({30, 120, 120, 120}, {0, 260 , 320, 320});
        // draw_save();
        // cont_pressed();
        // draw_element_cont();
        // comming_rect_cont();
    }
}
