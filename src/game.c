#include "logic/gamestate.c"
#include "logic/character.c"

void gamestate_dotick(gamestate* st) {
	struct entitylink* en = st->entities;

	while (en != NULL) {
		en->val.tick(st, en->val.data);
		en = en->next;
	}
}