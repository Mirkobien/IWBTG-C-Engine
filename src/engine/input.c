void initKeyBindings(KeyBindings* k)
{
    //TODO: Find a cleaner way for these multiple definitions
    #ifdef __SWITCH__
        k->bindings[KEY_LEFT] = 12 + 1;
        k->bindings[KEY_RIGHT] = 14 + 1;
        k->bindings[KEY_UP] = 13 + 1;
        k->bindings[KEY_DOWN] = 15 + 1;
        k->bindings[KEY_CONFIRM] = 0 + 1;
        k->bindings[KEY_CANCEL] = 1 + 1;
        //TODO: editor keys
        k->bindings[KEY_MENU] = 10 + 1;
        //k->bindings[KEY_LOAD_LEVEL] = SDLK_l + 1;
        //k->bindings[KEY_SAVE_LEVEL] = SDLK_s + 1;
        //k->bindings[KEY_CONSOLE] = SDLK_TAB + 1;
        k->bindings[KEY_JUMP] = 0 + 1;
        k->bindings[KEY_TILE_PICKER] = 9 + 1;
        k->bindings[KEY_RESTART] = 3 + 1;
        //k->bindings[KEY_FULLSCREEN_TOGGLE] = SDLK_F4 + 1;
        k->bindings[KEY_EDITOR_TOGGLE] = 8 + 1;
        k->bindings[KEY_SHOOT] = 2 + 1;
    #else
        k->bindings[KEY_LEFT] = SDLK_LEFT;
        k->bindings[KEY_RIGHT] = SDLK_RIGHT;
        k->bindings[KEY_UP] = SDLK_UP;
        k->bindings[KEY_DOWN] = SDLK_DOWN;
        k->bindings[KEY_CONFIRM] = SDLK_RETURN;
        k->bindings[KEY_CANCEL] = SDLK_SPACE;
        //editor keys
        k->bindings[KEY_EDITOR_T_TOGGLE] = SDLK_SPACE;
        k->bindings[KEY_MENU] = SDLK_ESCAPE;
        k->bindings[KEY_LOAD_LEVEL] = SDLK_l;
        k->bindings[KEY_SAVE_LEVEL] = SDLK_s;
        k->bindings[KEY_CONSOLE] = SDLK_TAB;
        k->bindings[KEY_JUMP] = SDLK_LSHIFT;
        k->bindings[KEY_TILE_PICKER] = SDLK_t;
        k->bindings[KEY_RESTART] = SDLK_r;
        k->bindings[KEY_FULLSCREEN_TOGGLE] = SDLK_F4;
        k->bindings[KEY_EDITOR_TOGGLE] = SDLK_e;
        k->bindings[KEY_SHOOT] = SDLK_z;
    #endif
}

int getKey(KeyBindings* k, KeyBinding key)
{
    return k->bindings[key];
}

void inputClearKeyboard(Input* i)
{
    memset(&i->keys, 0, MAX_KEYS);
    memset(&i->keysPressed, 0, MAX_KEYS);
    memset(&i->keysReleased, 0, MAX_KEYS);
}

bool checkMouseButton(Game* g, int button)
{
    return g->input.mouseButtons[button];
}

bool checkKey(Game* g, int key)
{
    if(g->input.frameVoid)
        return 0;
    return g->input.keys[getKey(&g->keyBindings, key) & 255];
}

bool checkKeyPressed(Game* g, int key)
{
    if(g->input.frameVoid)
        return 0;

	return g->input.keysPressed[getKey(&g->keyBindings, key) & 255];
}

bool checkKeyPressedDirect(Game* g, int key)
{
    if(g->input.frameVoid)
        return 0;
    return g->input.keysPressed[key & 255];
}

bool checkKeyReleased(Game* g, int key)
{
    if(g->input.frameVoid)
        return 0;
    return g->input.keysReleased[getKey(&g->keyBindings, key) & 255];
}

void setMousePosition(Game* g, int x, int y)
{
    g->input.mousePosition.x = (float)x / ((float)g->windowSize.x / g->size.x) + g->camera.x;
    g->input.mousePosition.y = (float)y / ((float)g->windowSize.y / g->size.y) + g->camera.y;
}