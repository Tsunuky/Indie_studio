/*
** EPITECH PROJECT, 2019
** testtexture
** File description:
** tes
*/

#include "Graph/lib.hpp"

int bot1 = 0;
int bot2 = 0;
int bot3 = 0;
int bot4 = 0;

int diff1 = 0;
int diff2 = 0;
int diff3 = 0;
int diff4 = 0;

int player_one = 0;
int player_two = 0;

void Mainenu::player_bot_draw()
{
    if (difficulty1[diff1] && bot1 == 1)
        difficulty1[diff1]->setVisible(true);
    if (difficulty2[diff2] && bot2 == 1)
        difficulty2[diff2]->setVisible(true);
    if (difficulty3[diff3] && bot3 == 1)
        difficulty3[diff3]->setVisible(true);
    if (difficulty4[diff4] && bot4 == 1)
        difficulty4[diff4]->setVisible(true);
    if (player_one == 1 || bot1 == 1) {
        _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, _clear[0]);
        if (!buttons["disable1"])
            draw_button(&buttons["disable1"], _clear[0], L"X", L"delete the player", 1);
        if (bot1 == 1){
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {740, 90, 780, 130});
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {960, 90, 1000, 130});
            if (buttons["prev_diff1"] == nullptr && buttons["next_diff1"] == nullptr) {
                draw_button(&buttons["prev_diff1"], {740, 90, 780, 130}, L"<", L"decrease the level", 1);
                draw_button(&buttons["next_diff1"], {960, 90, 1000, 130}, L">", L"increse the level", 1);
                draw_difficulty1(_diff[0]);
            }
        }
    }

    if (player_two == 1 || bot2 == 1) {
        _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, _clear[1]);
        if (!buttons["disable2"])
            draw_button(&buttons["disable2"], _clear[1], L"X", L"delete the player", 1);
        if (bot2 == 1){
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {740, 242, 780, 282});
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {960, 242, 1000, 282});
            if (buttons["prev_diff2"] == nullptr && buttons["next_diff2"] == nullptr) {
                draw_button(&buttons["prev_diff2"], {740, 242, 780, 282}, L"<", L"decrease the level", 1);
                draw_button(&buttons["next_diff2"], {960, 242, 1000, 282}, L">", L"increse the level", 1);
                draw_difficulty2(_diff[1]);
            }
        }
    }
    if(bot3 == 1) {
        _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, _clear[2]);;
        if (!buttons["disable3"])
            draw_button(&buttons["disable3"], _clear[2], L"X", L"delete the player", 1);
        if (bot3 == 1){
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {740, 394, 780, 434});
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {960, 394, 1000, 434});
            if (buttons["prev_diff3"] == nullptr && buttons["next_diff3"] == nullptr) {
                draw_button(&buttons["prev_diff3"], {740, 394, 780, 434}, L"<", L"decrease the level", 1);
                draw_button(&buttons["next_diff3"], {960, 394, 1000, 434}, L">", L"increse the level", 1);
                draw_difficulty3(_diff[2]);
            }
        }
    }
    if(bot4 == 1) {
        _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, _clear[3]);
        if (!buttons["disable4"])
            draw_button(&buttons["disable4"], _clear[3], L"X", L"delete the player", 1);
        if (bot4 == 1){
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {740, 546, 780, 586});
            _game->_graphicLibrary->getDriver()->draw2DRectangle({230, 27, 27, 27}, {960, 546, 1000, 586});
            if (buttons["prev_diff4"] == nullptr && buttons["next_diff4"] == nullptr) {
                draw_button(&buttons["prev_diff4"], {740, 546, 780, 586}, L"<", L"decrease the level", 1);
                draw_button(&buttons["next_diff4"], {960, 546, 1000, 586}, L">", L"increse the level", 1);
                draw_difficulty4(_diff[3]);
            }
        }
    }
}

void Mainenu::next_prev_map_pressed()
{
    if (buttons["next_map"]->isPressed()) {
        nb_map += 1;
        if (nb_map >= map_preset.size())
            nb_map = 0;
        buttons["next_map"]->setPressed(false);
    }
    if (buttons["prev_map"]->isPressed()) {
        nb_map -= 1;
        if (nb_map < 0)
            nb_map = map_preset.size() - 1;
        buttons["prev_map"]->setPressed(false);
    }
    if (buttons["add_player1"]->isPressed()) {
        buttons["add_player1"]->setPressed(false);
        buttons["add_bot1"]->setVisible(false);
        buttons["add_player1"]->setVisible(false);
        player_one = 1;
        nb_player += 1;
        if (static_text["playerone"] == nullptr)
            add_static_text("playerone", L"Player one", {600, 100, 660, 140});
    }
    if (buttons["add_bot1"]->isPressed()) {
        buttons["add_bot1"]->setPressed(false);

        buttons["add_bot1"]->setVisible(false);
        buttons["add_player1"]->setVisible(false);
        bot1 = 1;
        nb_bot += 1;
        if (static_text["bot1"] == nullptr)
            add_static_text("bot1", L"Computer 1", {600, 100, 660, 140});
    }
    if (buttons["add_player2"]->isPressed()) {
        buttons["add_player2"]->setPressed(false);
        buttons["add_bot2"]->setVisible(false);
        buttons["add_player2"]->setVisible(false);
        player_two = 1;
        nb_player += 1;
        if (static_text["playertwo"] == nullptr)
            add_static_text("playertwo", L"Player two", {600, 252, 660, 292});
    }
    if (buttons["add_bot2"]->isPressed()) {
        buttons["add_bot2"]->setPressed(false);
        buttons["add_bot2"]->setVisible(false);
        buttons["add_player2"]->setVisible(false);
        nb_bot += 1;
        bot2 = 1;
        if (static_text["bot2"] == nullptr)
            add_static_text("bot2", L"Computer 2", {600, 252, 660, 292});
    }
    if (buttons["add_bot3"]->isPressed()) {
        buttons["add_bot3"]->setVisible(false);
        buttons["add_bot3"]->setPressed(false);
        nb_bot += 1;
        bot3 = 1;
        if (static_text["bot3"] == nullptr)
            add_static_text("bot3", L"Computer 3", {600, 404, 660, 444});
    }
    if (buttons["add_bot4"]->isPressed()) {
        buttons["add_bot4"]->setVisible(false);
        buttons["add_bot4"]->setPressed(false);
        nb_bot += 1;
        bot4 = 1;
        if (static_text["bot4"] == nullptr)
            add_static_text("bot4", L"Computer 4", {600, 556, 660, 596});
    }
    if (buttons["start"]->isPressed()) {
        if (nb_player != 0) {
            clear_all_menu();
	    try {
		music.stop();
		if (!gameMusic.openFromFile("media/GameMusic.ogg"))
    			throw std::runtime_error("Could not load music");
    		gameMusic.setLoop(true);
    		gameMusic.play();
                Initializor init;
                Core core(dynamic_cast<LibContainer *>(_game), init.Game());
                core.launcher(nb_player, nb_bot, nb_map, "none");
		gameMusic.stop();
	    }
            catch (std::exception err) {
                err.what();
                return;
            } catch (...) {
                return;
            }
        }
    }
}

void Mainenu::comming_rect()
{
    if (_rect[0].UpperLeftCorner.X <= 320)
        return;
    for (size_t i = 0; i < _rect.size(); ++i)
        _rect[i].operator -= ({10, 0});
    for (size_t i = 0; i < _player.size(); ++i)
        _player[i].operator -= ({10, 0});
    for (size_t i = 0; i < _pdp.size(); ++i)
        _pdp[i].operator -= ({10, 0});
    remove_button(&buttons["next_map"]);
    remove_button(&buttons["prev_map"]);
    remove_button(&buttons["add_bot1"]);
    remove_button(&buttons["add_bot2"]);
    remove_button(&buttons["add_bot3"]);
    remove_button(&buttons["add_bot4"]);
    remove_button(&buttons["add_player1"]);
    remove_button(&buttons["add_player2"]);
    remove_button(&buttons["start"]);
    if (!buttons["next_map"] && !buttons["prev_map"]) {
        draw_button(&buttons["next_map"], _rect[2], L">", L"Next map", 1);
        draw_button(&buttons["prev_map"], _rect[3], L"<", L"Prev map", 1);
        draw_button(&buttons["add_bot1"], _rect[4], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_bot2"], _rect[5], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_bot3"], _rect[6], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_bot4"], _rect[7], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_player1"], _rect[8], L"Add player one", L"adding a player", 1);
        draw_button(&buttons["add_player2"], _rect[9], L"Add player two", L"adding a player", 1);
        draw_button(&buttons["start"], _rect[10], L"Start Party", L"Lunch the game", 1);
    }
}

void Mainenu::escape_rect()
{
    if (_rect[0].UpperLeftCorner.X > 1920) {
        in_menu = 0;
        return;
    }
    for (size_t i = 0; i < _rect.size(); ++i)
        _rect[i].operator += ({10, 0});
    for (size_t i = 0; i < _player.size(); ++i)
        _player[i].operator += ({10, 0});
    for (size_t i = 0; i < _pdp.size(); ++i)
        _pdp[i].operator += ({10, 0});
    remove_button(&buttons["next_map"]);
    remove_button(&buttons["prev_map"]);
    remove_button(&buttons["add_bot1"]);
    remove_button(&buttons["add_bot2"]);
    remove_button(&buttons["add_bot3"]);
    remove_button(&buttons["add_bot4"]);
    remove_button(&buttons["add_player1"]);
    remove_button(&buttons["add_player2"]);
    remove_button(&buttons["start"]);
    if (!buttons["next_map"] && !buttons["prev_map"]) {
        draw_button(&buttons["next_map"], _rect[2], L">", L"Next map", 1);
        draw_button(&buttons["prev_map"], _rect[3], L"<", L"Prev map", 1);
        draw_button(&buttons["add_bot1"], _rect[4], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_bot2"], _rect[5], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_bot3"], _rect[6], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_bot4"], _rect[7], L"Add a bot", L"adding a bot", 1);
        draw_button(&buttons["add_player1"], _rect[8], L"Add player one", L"adding a player", 1);
        draw_button(&buttons["add_player2"], _rect[9], L"Add player two", L"adding a player", 1);
        draw_button(&buttons["start"], _rect[10], L"Start Party", L"Lunch the game", 1);
    }
}

void Mainenu::draw_element()
{
    _game->_graphicLibrary->getDriver()->draw2DRectangle({240, 27, 27, 27}, _rect[0]);
    for (size_t i = 0; i < _pdp.size(); ++i) {
        _game->_graphicLibrary->getDriver()->draw2DRectangle({255, 120, 0, 120}, _player[i]);
        _game->_graphicLibrary->getDriver()->draw2DImage(sprite["PROFIL"], _pdp[i].UpperLeftCorner, {0,0,128,128}, 0, {255, 255, 255, 255}, true);
    }
    _game->_graphicLibrary->getDriver()->draw2DImage(map_preset[nb_map], _rect[1], {0,0,600,600}, 0);
    _game->_graphicLibrary->getDriver()->draw2DRectangle({255, 120, 0, 120}, _rect[10]);
}

void Mainenu::clear_player()
{
    if (buttons["disable1"] && buttons["disable1"]->isPressed()) {
        buttons["disable1"]->setVisible(false);
        remove_button(&buttons["disable1"]);
        buttons["disable1"] = nullptr;
        buttons["add_player1"]->setVisible(true);
        buttons["add_bot1"]->setVisible(true);
        if (static_text["playerone"] != nullptr) {
            static_text["playerone"]->remove();
            static_text["playerone"] = nullptr;
        }
        if (static_text["bot1"] != nullptr ) {
            static_text["bot1"]->remove();
            static_text["bot1"] = nullptr;
        }
        remove_button(&buttons["prev_diff1"]);
        remove_button(&buttons["next_diff1"]);
        if (difficulty1[diff1]) {
            difficulty1[diff1]->setVisible(false);
            difficulty1[diff1] = nullptr;
        }
        if (bot1 == 1)
            nb_bot -= 1;
        if (player_one == 1)
            nb_player -= 1;
        player_one = 0;
        bot1 = 0;
    }
    if (buttons["disable2"] && buttons["disable2"]->isPressed()) {
        buttons["disable2"]->setVisible(false);
        remove_button(&buttons["disable2"]);
        buttons["add_player2"]->setVisible(true);
        buttons["add_bot2"]->setVisible(true);
        if (static_text["playertwo"] != nullptr) {
            static_text["playertwo"]->remove();
            static_text["playertwo"] = nullptr;
        }
        if (static_text["bot2"] != nullptr) {
            static_text["bot2"]->remove();
            static_text["bot2"] = nullptr;
        }
        remove_button(&buttons["prev_diff2"]);
        remove_button(&buttons["next_diff2"]);
        if (difficulty2[diff2]) {
            difficulty2[diff2]->setVisible(false);
            difficulty2[diff2] = nullptr;
        }
        if (bot2 == 1)
            nb_bot -= 1;
        if (player_two == 1)
            nb_player -= 1;
        player_two = 0;
        bot2 = 0;
    }
    if (buttons["disable3"] && buttons["disable3"]->isPressed()) {
        buttons["disable3"]->setVisible(false);
        remove_button(&buttons["disable3"]);
        buttons["add_bot3"]->setVisible(true);
        if (static_text["bot3"] != nullptr) {
            static_text["bot3"]->remove();
            static_text["bot3"] = nullptr;
        }
        remove_button(&buttons["prev_diff3"]);
        remove_button(&buttons["next_diff3"]);
        if (difficulty3[diff3]) {
            difficulty3[diff3]->setVisible(false);
            difficulty3[diff3] = nullptr;
        }
        if (bot3 == 1)
            nb_bot -= 1;
        bot3 = 0;
    }
    if (buttons["disable4"] && buttons["disable4"]->isPressed()) {
        buttons["disable4"]->setVisible(false);
        remove_button(&buttons["disable4"]);
        buttons["add_bot4"]->setVisible(true);
        if (static_text["bot4"] != nullptr) {
            static_text["bot4"]->remove();
            static_text["bot4"] = nullptr;
        }
        remove_button(&buttons["prev_diff4"]);
        remove_button(&buttons["next_diff4"]);
        if (difficulty4[diff4]) {
            difficulty4[diff4]->setVisible(false);
            difficulty4[diff4] = nullptr;
        }
        if (bot4 == 1)
            nb_bot -= 1;
        bot4 = 0;
    }
    if (buttons["prev_diff1"] && buttons["prev_diff1"]->isPressed()) {
        buttons["prev_diff1"]->setPressed(false);
        difficulty1[diff1]->setVisible(false);
        diff1 -= 1;
        if (diff1 < 0)
            diff1 = 2;
        if (diff1 > 2)
            diff1 = 0;
    }
    if (buttons["next_diff1"] && buttons["next_diff1"]->isPressed()) {
        buttons["next_diff1"]->setPressed(false);
        difficulty1[diff1]->setVisible(false);
        diff1 += 1;
        if (diff1 < 0)
            diff1 = 2;
        if (diff1 > 2)
            diff1 = 0;
    }
    if (buttons["prev_diff2"] && buttons["prev_diff2"]->isPressed()) {
        buttons["prev_diff2"]->setPressed(false);
        difficulty2[diff2]->setVisible(false);
        diff2 -= 1;
        if (diff2 < 0)
            diff2 = 2;
        if (diff2 > 2)
            diff2 = 0;
    }
    if (buttons["next_diff2"] && buttons["next_diff2"]->isPressed()) {
        buttons["next_diff2"]->setPressed(false);
        difficulty2[diff2]->setVisible(false);
        diff2 += 1;
        if (diff2 < 0)
            diff2 = 2;
        if (diff2 > 2)
            diff2 = 0;
    }
    if (buttons["prev_diff3"] && buttons["prev_diff3"]->isPressed()) {
        buttons["prev_diff3"]->setPressed(false);
        difficulty3[diff3]->setVisible(false);
        diff3 -= 1;
        if (diff3 < 0)
            diff3 = 2;
        if (diff3 > 2)
            diff3 = 0;
    }
    if (buttons["next_diff3"] && buttons["next_diff3"]->isPressed()) {
        buttons["next_diff3"]->setPressed(false);
        difficulty3[diff3]->setVisible(false);
        diff3 += 1;
        if (diff3 < 0)
            diff3 = 2;
        if (diff3 > 2)
            diff3 = 0;
    }
    if (buttons["prev_diff4"] && buttons["prev_diff4"]->isPressed()) {
        buttons["prev_diff4"]->setPressed(false);
        difficulty4[diff4]->setVisible(false);
        diff4 -= 1;
        if (diff4 < 0)
            diff4 = 2;
        if (diff4 > 2)
            diff4 = 0;
    }
    if (buttons["next_diff4"] && buttons["next_diff4"]->isPressed()) {
        buttons["next_diff4"]->setPressed(false);
        difficulty4[diff4]->setVisible(false);
        diff4 += 1;
        if (diff4 < 0)
            diff4 = 2;
        if (diff4 > 2)
            diff4 = 0;
    }
}

void Mainenu::clear_all_player()
{
    remove_button(&buttons["disable1"]);
    if (static_text["playerone"] != nullptr) {
        static_text["playerone"]->remove();
        static_text["playerone"] = nullptr;
    }
    if (static_text["bot1"] != nullptr ) {
        static_text["bot1"]->remove();
        static_text["bot1"] = nullptr;
    }
    remove_button(&buttons["prev_diff1"]);
    remove_button(&buttons["next_diff1"]);
    player_one = 0;
    bot1 = 0;
    if (difficulty1[diff1]) {
        difficulty1[diff1]->setVisible(false);
        difficulty1[diff1] = nullptr;
    }
    remove_button(&buttons["disable2"]);
    buttons["add_player2"]->setVisible(true);
    buttons["add_bot2"]->setVisible(true);
    if (static_text["playertwo"] != nullptr) {
        static_text["playertwo"]->remove();
        static_text["playertwo"] = nullptr;
    }
    if (static_text["bot2"] != nullptr) {
        static_text["bot2"]->remove();
        static_text["bot2"] = nullptr;
    }
    remove_button(&buttons["prev_diff2"]);
    remove_button(&buttons["next_diff2"]);
    player_two = 0;
    bot2 = 0;
    if (difficulty2[diff2]) {
        difficulty2[diff2]->setVisible(false);
        difficulty2[diff2] =  nullptr;
    }
    remove_button(&buttons["disable3"]);
    buttons["add_bot3"]->setVisible(true);
    if (static_text["bot3"] != nullptr) {
        static_text["bot3"]->remove();
        static_text["bot3"] = nullptr;
    }
    remove_button(&buttons["prev_diff3"]);
    remove_button(&buttons["next_diff3"]);
    bot3 = 0;
    if (difficulty3[diff3]) {
        difficulty3[diff3]->setVisible(false);
        difficulty3[diff3] = nullptr;
    }
    remove_button(&buttons["disable4"]);
    buttons["add_bot4"]->setVisible(true);
    if (static_text["bot4"] != nullptr) {
        static_text["bot4"]->remove();
        static_text["bot4"] = nullptr;
    }
    remove_button(&buttons["prev_diff4"]);
    remove_button(&buttons["next_diff4"]);
    bot4 = 0;
    if (difficulty4[diff4]) {
        difficulty4[diff4]->setVisible(false);
        difficulty4[diff4] = nullptr;
    }
}

void Mainenu::draw_difficulty1(rect<s32> pos)
{
    difficulty1[0] = _game->_graphicLibrary->getEnv()->addStaticText(L"Easy", pos);
    difficulty1[1] = _game->_graphicLibrary->getEnv()->addStaticText(L"Normal", pos);
    difficulty1[2] = _game->_graphicLibrary->getEnv()->addStaticText(L"Hard", pos);
    difficulty1[0]->setVisible(false);
    difficulty1[1]->setVisible(false);
    difficulty1[2]->setVisible(false);
}

void Mainenu::draw_difficulty2(rect<s32> pos)
{
    difficulty2[0] = _game->_graphicLibrary->getEnv()->addStaticText(L"Easy", pos);
    difficulty2[1] = _game->_graphicLibrary->getEnv()->addStaticText(L"Normal", pos);
    difficulty2[2] = _game->_graphicLibrary->getEnv()->addStaticText(L"Hard", pos);
    difficulty2[0]->setVisible(false);
    difficulty2[1]->setVisible(false);
    difficulty2[2]->setVisible(false);
}
void Mainenu::draw_difficulty3(rect<s32> pos)
{
    difficulty3[0] = _game->_graphicLibrary->getEnv()->addStaticText(L"Easy", pos);
    difficulty3[1] = _game->_graphicLibrary->getEnv()->addStaticText(L"Normal", pos);
    difficulty3[2] = _game->_graphicLibrary->getEnv()->addStaticText(L"Hard", pos);
    difficulty3[0]->setVisible(false);
    difficulty3[1]->setVisible(false);
    difficulty3[2]->setVisible(false);
}
void Mainenu::draw_difficulty4(rect<s32> pos)
{
    difficulty4[0] = _game->_graphicLibrary->getEnv()->addStaticText(L"Easy", pos);
    difficulty4[1] = _game->_graphicLibrary->getEnv()->addStaticText(L"Normal", pos);
    difficulty4[2] = _game->_graphicLibrary->getEnv()->addStaticText(L"Hard", pos);
    difficulty4[0]->setVisible(false);
    difficulty4[1]->setVisible(false);
    difficulty4[2]->setVisible(false);
}

void Mainenu::draw_menu_new()
{
    if (in_menu == -1) {
        draw_element();
        escape_rect();
        clear_all_player();
    } else {
        in_menu = 1;
        if (buttons["back_new_game"] == nullptr)
            draw_button(&buttons["back_new_game"], {220, 200, 320, 260},L"<", L"Back to the menu", 1);
        _game->_graphicLibrary->getDriver()->draw2DRectangle({30, 120, 120, 120}, {0, 200 , 320, 260});
        draw_element();
        comming_rect();
        player_bot_draw();
        next_prev_map_pressed();
        clear_player();
    }
}
