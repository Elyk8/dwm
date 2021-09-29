Layout *last_layout;

void
fullscreen(const Arg *arg)
{
	int monocle_pos = 0;

	if (last_layout == NULL) {
		for (monocle_pos = 0, last_layout = (Layout *)layouts; !last_layout->arrange
			|| (abs(last_layout->preset.masteraxis) != MONOCLE
			&& abs(last_layout->preset.layout) != NO_SPLIT
			&& abs(last_layout->preset.stack1axis != MONOCLE)); 
			monocle_pos++, last_layout++);
		for (last_layout = (Layout *)layouts; last_layout != selmon->lt[selmon->sellt]; last_layout++);
		setlayout(&((Arg) { .v = &layouts[monocle_pos] }));
	} else {
		setlayout(&((Arg) { .v = last_layout }));
	}
}
