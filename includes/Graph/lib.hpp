

#ifndef __LIB__HPP__
#define __LIB__HPP__

#include <irrlicht.h>
#include <iostream>
#include <vector>
#include <map>
#include <memory>


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

 //graph into
#include "Core/Core.hpp"

class Mainenu {
    public:
	    Mainenu(LibContainer * game): nb_map(0), in_menu(0), lunch(false)
	    {
		if (!music.openFromFile("media/menuMusic.ogg"))
			throw std::runtime_error("Could not load music");
		music.setLoop(true);
		music.play();
		_game = (LibContainerIrrlicht *)game;
		_skin = _game->_graphicLibrary->getEnv()->getSkin();
		_font = _game->_graphicLibrary->getEnv()->getFont("./media/fonthaettenschweiler.bmp");

		if (_font)
    	_skin->setFont(_font);
	_skin->setFont(_game->_graphicLibrary->getEnv()->getBuiltInFont(), EGDF_TOOLTIP);
	_skin->setColor(EGDC_BUTTON_TEXT ,{255,255,255,255});

	sprite.emplace("VISIBLE", _game->_graphicLibrary->getDriver()->getTexture("./media/alpha.png"));
	sprite.emplace("BACKGROUND", _game->_graphicLibrary->getDriver()->getTexture("./media/background.png"));
	sprite.emplace("PROFIL", _game->_graphicLibrary->getDriver()->getTexture("./media/100x.png"));
	map_preset.push_back(_game->_graphicLibrary->getDriver()->getTexture("./media/map1.png"));
	map_preset.push_back(_game->_graphicLibrary->getDriver()->getTexture("./media/map2.png"));
	map_preset.push_back(_game->_graphicLibrary->getDriver()->getTexture("./media/map3.png"));
	}
	virtual ~Mainenu() = default;
    private:
	    void draw_menu();
	    void setImageButton();
	    void Button_pressed();
	    void draw_button(IGUIButton **, rect<s32>,  const wchar_t *, const wchar_t *, int);
	    void remove_button(IGUIButton **);

    public:
	    void run() {
		if (_game->_graphicLibrary->getDivice() == 0)
    	return;
	_game->_graphicLibrary->getDivice()->setWindowCaption(L"Irrlicht Engine - Menu Test");
	_game->_graphicLibrary->getDivice()->setResizable(true);
	setImageButton();
	while(_game->_graphicLibrary->getDivice()->run() && _game->_graphicLibrary->getDriver()) {
    	if (_game->_graphicLibrary->getDivice()->isWindowActive()) {
		_game->_graphicLibrary->getDriver()->beginScene(true, false, {0, 0, 0, 0});
		draw_menu();
		Button_pressed();
		_game->_graphicLibrary->getEnv()->drawAll();
		_game->_graphicLibrary->getDriver()->endScene();
    	}
	}
	}

    private:
	    void draw_element();
	    void menu_new();
	    void next_prev_map_pressed();
	    void comming_rect();
	    void escape_rect();
	    void player_bot_draw();
	    void clear_player();
	    void draw_menu_continu();
	    void draw_menu_multi();
	    void draw_menu_option();
	    void draw_menu_new();
	    void comming_rect_multi();
	    void escape_rect_multi();
	    void draw_multi_element();
	    void choice_pressed();
	    void clear_all_player();
		void comming_rect_cont();
		void escape_rect_cont();
		void draw_element_cont();
		void cont_pressed();
		void draw_save();
		void clear_cont();
	    void draw_difficulty1(rect<s32>);
	    void draw_difficulty2(rect<s32>);
	    void draw_difficulty3(rect<s32>);
	    void draw_difficulty4(rect<s32>);
	    void add_static_text(std::string name, const wchar_t *text, rect<s32> pos);
	    void add_insert_text(std::string name, const wchar_t *text, rect<s32> pos);
	    void clear_all_menu();
	    bool getFlunch() { return lunch; };
	    int getNbplayer() { return nb_player; };
	    int getNbbot() { return nb_bot; };

    private:
	    IGUISkin *_skin;
	    IGUIFont* _font;

	    std::map<std::string, IGUIButton *> buttons;
	    std::map<std::string, ITexture *> sprite;
	    std::map<std::string, IGUIEditBox *> insert_text;
	    std::map<std::string, IGUIStaticText *> static_text;
	    std::map<int ,IGUIStaticText *> difficulty1;
	    std::map<int ,IGUIStaticText *> difficulty2;
	    std::map<int ,IGUIStaticText *> difficulty3;
	    std::map<int ,IGUIStaticText *> difficulty4;
		std::map<int ,IGUIStaticText *> save;
	    std::vector<ITexture *> map_preset;

	    std::vector<rect<s32>> _rect = { {1920, 0, 3520, 1080}, {3000, 20, 3500, 520}, {3460, 540, 3500, 580}, {3000, 540, 3040, 580}, {2800, 90, 2920, 130}, {2800, 240, 2920, 280}, {2800, 390, 2920, 430}, {2800, 540, 2920, 580}, {2600, 90, 2720, 130}, {2600, 240, 2720, 280}, {3060, 540, 3440, 580}};
	    std::vector<rect<s32>> _pdp = { {1950, 40 , 2960, 172}, {360+1600, 194, 488+1600, 322}, {360+1600, 346, 488+1600, 474}, {360+1600, 498, 488+1600, 626} };
	    std::vector<rect<s32>> _player = { {1950, 40 , 2960, 172}, {1950, 192 , 2960, 324}, {1950, 344 , 2960, 476}, {1950, 496 , 2960, 628} };
	    std::vector<rect<s32>> _clear = {{1300, 40, 1360, 172}, {1300, 192 , 1360, 324}, {1300, 344 , 1360, 476}, {1300, 496 , 1360, 628} };
	    std::vector<rect<s32>> _multirect = {{320, 1080, 1920, 1460}, {820, 1200, 1020, 1260}, {1220, 1200, 1420, 1260}};
	    std::vector<rect<s32>> _diff = {{840, 100, 900, 140}, {840, 252, 900, 292}, {840, 404, 900, 444}, {840, 556, 900, 596}};
		std::vector<rect<s32>> _cont = {{360+1600, 140, 400+1600, 180}, {520+1600, 140, 560+1600, 180}, {580+1600, 140, 700+1600, 180}, {350+1600, 120, 710+1600, 200}, {405+1600, 150, 490+1600, 190}};

	    std::string ip;
	    LibContainerIrrlicht *_game;

	    bool lunch;
	    int in_menu;
	    int nb_map;
	    int nb_player = 0;
	    int nb_bot = 0;
	    sf::Music gameMusic;
	sf::Music music;

};

#endif
