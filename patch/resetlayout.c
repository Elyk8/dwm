void
resetlayout(const Arg *arg)
{
	Arg default_layout = {.v = &layouts[0]};
	Arg default_mfact = {.f = mfact + 1};

	setlayout(&default_layout);
	setmfact(&default_mfact);
}
