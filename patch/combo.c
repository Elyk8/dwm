static int combo = 0;

void
keyrelease(XEvent *e)
{
	combo = 0;
}

void
combotag(const Arg *arg)
{
	if (selmon->sel && arg->ui & TAGMASK) {
		if (selmon->sel->switchtag)
			selmon->sel->switchtag = 0;
		if (combo) {
			selmon->sel->tags |= arg->ui & TAGMASK;
		} else {
			combo = 1;
			selmon->sel->tags = arg->ui & TAGMASK;
		}
		focus(NULL);
		arrange(selmon);
		if ((arg->ui & TAGMASK) != selmon->tagset[selmon->seltags])
			view(arg);
	}
}

void
comboview(const Arg *arg)
{
	unsigned newtags = arg->ui & TAGMASK;
	if (combo) {
		selmon->tagset[selmon->seltags] |= newtags;
	} else {
		selmon->seltags ^= 1;	/*toggle tagset*/
		combo = 1;
		if (newtags) {
			pertagview(&((Arg) { .ui = newtags }));
		}
	}
	focus(NULL);
	arrange(selmon);
}

