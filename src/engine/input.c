void initKeyBindings(KeyBindings* k)
{
    //TODO: Make these bindings make sense code-wise
    k->bindings[KEY_LEFT] = 12 + 1;
    k->bindings[KEY_RIGHT] = 14 + 1;
    k->bindings[KEY_UP] = 13 + 1;
    k->bindings[KEY_DOWN] = 15 + 1;
    //k->bindings[KEY_CONFIRM] = 0 + 1;
    k->bindings[KEY_CANCEL] = 11 + 1;
	//k->bindings[KEY_MENU] = 10 + 1;
    //k->bindings[KEY_LOAD_LEVEL] = SDLK_l + 1;
    //k->bindings[KEY_SAVE_LEVEL] = SDLK_s + 1;
    //k->bindings[KEY_CONSOLE] = SDLK_TAB + 1;
    k->bindings[KEY_JUMP] = 0 + 1;
    k->bindings[KEY_TILE_PICKER] = 9 + 1;
    k->bindings[KEY_RESTART] = 3 + 1;
    //k->bindings[KEY_FULLSCREEN_TOGGLE] = SDLK_F4 + 1;
    k->bindings[KEY_EDITOR_TOGGLE] = 10 + 1;
    k->bindings[KEY_SHOOT] = 2 + 1;
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