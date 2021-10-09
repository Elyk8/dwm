/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERM "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 2;   /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static int nomodbuttons                  = 1;   /* allow client mouse button bindings that have no modifier */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 15;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 15;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int usealtbar               = 1;   /* 1 means use non-dwm status bar */
static const char *altbarclass           = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd             = "$HOME/.config/polybar/launch"; /* Alternate bar launch command */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static int floatposgrid_x                = 5;  /* float grid columns */
static int floatposgrid_y                = 5;  /* float grid rows */
/* Indicators: see patch/bar_indicators.h for options */
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static int fakefsindicatortype           = INDICATOR_PLUS;
static int floatfakefsindicatortype      = INDICATOR_PLUS_AND_LARGER_SQUARE;
static int stickyindicatortype           = INDICATOR_BOTTOM_BAR;
static const char *fonts[]               = {
	"Iosevka Nerd Font:bold:italic:size=10:antialias=true:autohint=true", 
	"Twemoji:size=8:antialias=true:autohint=true"
};

static char c000000[]                    = "#000000"; // placeholder value


static char normfgcolor[]                = "#A9B1D6";
static char normbgcolor[]                = "#1A1B26";
static char normbordercolor[]            = "#1A1B26";
static char normfloatcolor[]             = "#9A7ECC";

static char selfgcolor[]                 = "#1A1B26";
static char selbgcolor[]                 = "#A9B1D6";
static char selbordercolor[]             = "#61AFEF";
static char selfloatcolor[]              = "#9A7ECC";

static char titlenormfgcolor[]           = "#A9B1D6";
static char titlenormbgcolor[]           = "#1A1B26";
static char titlenormbordercolor[]       = "#1A1B26";
static char titlenormfloatcolor[]        = "#9A7ECC";

static char titleselfgcolor[]            = "#1A1B26";
static char titleselbgcolor[]            = "#1A1B26";
static char titleselbordercolor[]        = "#A9B1D6";
static char titleselfloatcolor[]         = "#1A1B26";

static char tagsnormfgcolor[]            = "#A9B1D6";
static char tagsnormbgcolor[]            = "#1A1B26";
static char tagsnormbordercolor[]        = "#1A1B26";
static char tagsnormfloatcolor[]         = "#9A7ECC";

static char tagsselfgcolor[]             = "#A9B1D6";
static char tagsselbgcolor[]             = "#414868";
static char tagsselbordercolor[]         = "#414868";
static char tagsselfloatcolor[]          = "#4E5173";

static char hidnormfgcolor[]             = "#c278b6";
static char hidnormbgcolor[]             = "#222222";
static char hidselfgcolor[]              = "#D288C6";
static char hidselbgcolor[]              = "#111111";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};


static const char *const autostart[] = {
	"shotkey", NULL,
	NULL /* terminate */
};


const char *spcmd1[] = {TERM, "-n", "spterm", "-g", "120x30", NULL};
const char *spcmd2[] = {TERM, "-n", "spcalc", "-f", "monospace:size=10", "-g", "50x20", "-e", "bc", "-lq", NULL};
const char *spcmd3[] = {TERM, "-n", "spfm", "-g", "120x30", "-e", "lf-run", NULL };

static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
	{"spfm",        spcmd3},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *  WM_CLASS(STRING) = instance, class
	 *  WM_NAME(STRING) = title
	 *  WM_WINDOW_ROLE(STRING) = role
	 *  _NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Brave-browser", .tags = 1 << 3, .isfakefullscreen = 1)
	RULE(.class = "Brave-browser-nightly", .tags = 1 << 3, .isfakefullscreen = 1)
	RULE(.class = "Soffice", .isfakefullscreen = 1)
	RULE(.class = "obsidian", .tags = 1 << 2, .isfakefullscreen = 1)
	RULE(.role = "pop-up", .isfloating = 1)
	RULE(.role = "GtkFileChooserDialog", .isfloating = 1, .noswallow = 1)
	RULE(.class = "zoom", .tags = 1 << 7, .isfakefullscreen = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 8)
	RULE(.class = "Virt-manager", .tags = 1 << 8, .isfakefullscreen = 1)
	RULE(.class = "discord", .tags = 1 << 8, .isfakefullscreen = 1)
	RULE(.class = "qBittorrent", .tags = 1 << 6)
	RULE(.class = "Zathura", .noswallow = 1)
	RULE(.class = "sioyek", .noswallow = 1)
	RULE(.class = "Yad", .isfloating = 1)
	RULE(.class = "MATLAB R2021b - academic use", .tags = 1 << 5, .noswallow = 1)
	RULE(.class = "MATLAB R2021b", .tags = 1 << 5, .noswallow = 1)
	RULE(.class = "MATLABWindow", .tags = 1 << 5, .noswallow = 1)
	RULE(.class = "Dragon-drag-and-drop", .noswallow = 1)
	RULE(.class = TERMCLASS, .isterminal = 1)
	RULE(.title = "Event Tester", .noswallow = 1)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1, .isterminal = 1)
	RULE(.instance = "spcalc", .tags = SPTAG(1), .isfloating = 1, .isterminal = 1)
	RULE(.instance = "spfm", .tags = SPTAG(2), .isfloating = 1, .isterminal = 1)
	RULE(.instance = "cheatsheet", .isfloating = 1)
	RULE(.instance = "Mansearch - Viewer", .isfloating = 1)
	RULE(.instance = "weatherdisplay", .isfloating = 1)
	RULE(.title = "Picture-in-picture", .isfloating = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {{ -2}};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */



static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
	{ "[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "|||",      flextile,         { -1, -1, NO_SPLIT, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // columns
	{ "||T",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
	{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "[]#",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, GAPPLESSGRID, 0, NULL } }, // stackgrid
	{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
 	{ "><>",      NULL,             { -1, -1 } },    /* no layout function means floating behavior */
	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
	{ NULL,       NULL,             {0} },    /* end of layouts marker for cyclelayouts */
	// { "||=",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
};

#define Shift ShiftMask
#define Ctrl ControlMask
#define Alt Mod1Mask
#define AltGr Mod3Mask
#define Super Mod4Mask
#define ShiftGr Mod5Mask

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                    KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|Ctrl,               KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|Shift,              KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|Ctrl|Shift,         KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Alt|ShiftMask,      KEY,      swaptags,       {.ui = 1 << TAG} }, \
	{ MODKEY|Alt,                KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Alt|Ctrl,           KEY,      tagprevmon,     {.ui = 1 << TAG} }, \

#define LAYOUTSKEYS(KEY,LAYOUT) \
	{ MODKEY,                    KEY,      setlayout,      {.v = &layouts[LAYOUT - 1]} }, \

#define SCRATCHKEYSHIFT(KEY,NUM) \
	{ MODKEY|Shift,              KEY,      togglescratch,  {.ui = NUM } }, \

#define SCRATCHKEYS(KEY,NUM) \
	{ MODKEY,                    KEY,      togglescratch,  {.ui = NUM } }, \
	{ MODKEY|Alt,                KEY,      setscratch,     {.ui = NUM } }, \
	{ MODKEY|Alt|Shift,          KEY,      removescratch,  {.ui = NUM } }, \


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
/* #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } */

/* commands */
static const char *termcmd[]  = { "st", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

static Key keys[] = {
	// KEYBOARD BINDINGS

	/* modifier                  key               function                argument */
	// Tags management
	TAGKEYS(                     XK_1,                                     0) // Tag 1
	TAGKEYS(                     XK_2,                                     1) // Tag 2
	TAGKEYS(                     XK_3,                                     2) // Tag 3
	TAGKEYS(                     XK_4,                                     3) // Tag 4
	TAGKEYS(                     XK_5,                                     4) // Tag 5
	TAGKEYS(                     XK_6,                                     5) // Tag 6
	TAGKEYS(                     XK_7,                                     6) // Tag 7
	TAGKEYS(                     XK_8,                                     7) // Tag 8
	TAGKEYS(                     XK_9,                                     8) // Tag 9
	{ MODKEY,                    XK_0,             view,                   {.ui = ~SPTAGMASK } }, // Display all tags
	{ MODKEY|Shift,              XK_0,             tag,                    {.ui = ~SPTAGMASK } }, // Make all windows in current tag appear on all tags

	{ MODKEY,                    XK_Tab,           view,                   {0} }, // Toggle back to previously focused tag
	{ MODKEY,                    XK_backslash,     view,                   {0} }, // Toggle back to previously focused tag
	{ MODKEY|Shift,              XK_Tab,           shiftview,              { .i = -1 } }, // Backward cycle through tags 
	{ MODKEY|Shift,              XK_backslash,     shiftview,              { .i = +1 } }, // Forward cycle through tags 

	{ MODKEY,                    XK_w,             shiftviewclients,       { .i = -1 } }, // Backward cycle through tags 
	{ MODKEY,                    XK_e,             shiftviewclients,       { .i = +1 } }, // Forward cycle through tags 
	{ MODKEY|Shift,              XK_w,             shiftview,              { .i = -1 } }, // Backward cycle through tags 
	{ MODKEY|Shift,              XK_e,             shiftview,              { .i = +1 } }, // Forward cycle through tags 

	// Layouts management
	LAYOUTSKEYS(                 XK_F1,                                    1)
	LAYOUTSKEYS(                 XK_F2,                                    2)
	LAYOUTSKEYS(                 XK_F3,                                    3)
	LAYOUTSKEYS(                 XK_F4,                                    4)
	LAYOUTSKEYS(                 XK_F5,                                    5)
	LAYOUTSKEYS(                 XK_F6,                                    6)
	LAYOUTSKEYS(                 XK_F7,                                    7)
	LAYOUTSKEYS(                 XK_F8,                                    8)
	LAYOUTSKEYS(                 XK_F9,                                    9)
	LAYOUTSKEYS(                 XK_F10,                                   10)
	LAYOUTSKEYS(                 XK_F11,                                   11)
	LAYOUTSKEYS(                 XK_F12,                                   12)

	{ MODKEY,                    XK_bracketleft,   rotatelayoutaxis,       {.i = -1 } }, // cycle through the available layout splits (horizontal, vertical, centered, no split, etc.)
	{ MODKEY,                    XK_bracketright,  rotatelayoutaxis,       {.i = +1 } }, // cycle through the available layout splits (horizontal, vertical, centered, no split, etc.)
	{ MODKEY|Alt,                XK_bracketleft,   rotatelayoutaxis,       {.i = -2 } }, // cycle through the available tiling arrangements for the master area
	{ MODKEY|Alt,                XK_bracketright,  rotatelayoutaxis,       {.i = +2 } }, // cycle through the available tiling arrangements for the master area
	{ MODKEY|Shift,              XK_bracketleft,   rotatelayoutaxis,       {.i = -3 } }, // cycle through the available tiling arrangements for the primary (first) stack area
	{ MODKEY|Shift,              XK_bracketright,  rotatelayoutaxis,       {.i = +3 } }, // cycle through the available tiling arrangements for the primary (first) stack area
	{ MODKEY|Ctrl,               XK_bracketleft,   rotatelayoutaxis,       {.i = -4 } }, // cycle through the available tiling arrangements for the secondary stack area
	{ MODKEY|Ctrl,               XK_bracketright,  rotatelayoutaxis,       {.i = +4 } }, // cycle through the available tiling arrangements for the secondary stack area
	{ MODKEY|Ctrl,               XK_m,             mirrorlayout,           {0} }, // flip the master and stack areas

	// Clients management
	{ MODKEY,                    XK_k,             focusstack,             {.i = -1 } }, // Focus client to the up
	{ MODKEY,                    XK_j,             focusstack,             {.i = +1 } }, // Focus client to the down

	{ MODKEY,                    XK_h,             setmfact,               {.f = -0.05} }, // Increase master horizontal weight
	{ MODKEY,                    XK_l,             setmfact,               {.f = +0.05} }, // Decrease master horizontal weight
	{ MODKEY|Shift,              XK_h,             setcfact,               {.f = +0.25} }, // Increase client vertical weight
	{ MODKEY|Shift,              XK_l,             setcfact,               {.f = -0.25} }, // Decrease client vertical weight

	{ MODKEY,                    XK_comma,         focusmon,               {.i = -1 } }, // focus on the previous monitor, if any
	{ MODKEY,                    XK_period,        focusmon,               {.i = +1 } }, // focus on the next monitor, if any
	{ MODKEY|Shift,              XK_comma,         tagmon,                 {.i = -1 } }, // Move tag to previous monitor
	{ MODKEY|Shift,              XK_period,        tagmon,                 {.i = +1 } }, // Move tag to next monitor

	{ Ctrl|Alt,                  XK_Tab,           togglenomodbuttons,     {0} }, // disables / enables keybindings that are not accompanied by any modifier buttons for a client

	{ MODKEY,                    XK_i,             incnmaster,             {.i = +1 } }, // increase the number of clients in the master area
	{ MODKEY,                    XK_u,             incnmaster,             {.i = -1 } }, // decrease the number of clients in the master area
	{ MODKEY|Ctrl,               XK_i,             incnstack,              {.i = +1 } }, // increase the number of clients in the primary (first) stack area
	{ MODKEY|Ctrl,               XK_u,             incnstack,              {.i = -1 } }, // increase the number of clients in the primary (first) stack area

	{ MODKEY,                    XK_Left,          focusdir,               {.i = 0 } }, // Focus client to the left
	{ MODKEY,                    XK_Right,         focusdir,               {.i = 1 } }, // Focus client to the right
	{ MODKEY,                    XK_Up,            focusdir,               {.i = 2 } }, // Focus client to the up
	{ MODKEY,                    XK_Down,          focusdir,               {.i = 3 } }, // Focus client to the down

	{ MODKEY,                    XK_Left,          focusmon,               {.i = -1 } }, // Change focus to previous monitor
	{ MODKEY|Shift,              XK_Left,          tagmon,                 {.i = -1 } }, // Move tag to previous monitor
	{ MODKEY,                    XK_Right,         focusmon,               {.i = +1 } }, // Change focus to next monitor
	{ MODKEY|Shift,              XK_Right,         tagmon,                 {.i = +1 } }, // Move tag to next monitor

	{ MODKEY|Shift,              XK_j,             inplacerotate,          {.i = +2 } }, // Rotate stack and master clockwise
	{ MODKEY|Shift,              XK_k,             inplacerotate,          {.i = -2 } }, // Rotate stack and master anticlockwise

	{ MODKEY,                    XK_f,             switchcol,              {0} },

	{ MODKEY,                    XK_q,             killclient,             {0} }, // Close the selected client
	{ MODKEY|Shift,              XK_q,             killunsel,              {0} }, // Close all but the selected window

	{ MODKEY|Shift,              XK_BackSpace,     self_restart,           {0} }, // restart dusk
	{ MODKEY|Ctrl,               XK_BackSpace,     quit,                   {0} }, // exit dusk

	{ MODKEY,                    XK_m,             zoom,                   {0} }, // Swap selected stack client with master, or previously selected stack client with the master

	{ MODKEY,                    XK_g,             togglefloating,         {0} }, // Toggle window from float to tiling and vice-versa
	{ MODKEY|Shift,              XK_g,             floatpos,               {.v = "50% 50% 80% 80%" } }, // center client and take up 80% of the screen

	// Desktop management
	{ MODKEY,                    XK_b,             togglebar,              {0} }, // Toggle dwmbar visibility. Affect all tags

	{ MODKEY,                    XK_s,             togglesticky,           {0} }, // Make window appear on all tags


	{ MODKEY,                    XK_space,         setlayout,              {.v = &layouts[12]} },
	/* { MODKEY,                    XK_space,         togglefullscreen,       {0} }, */
	{ MODKEY|Shift,              XK_space,         togglefakefullscreen,   {0} }, // Toggle fakefullscreen property of selected client

	// Gaps mamagement
	{ MODKEY,                    XK_z,             incrgaps,               {.i = +3 } }, // Increase gap size by 3
	{ MODKEY,                    XK_x,             incrgaps,               {.i = -3 } }, // Decrease gap size by 3

	{ MODKEY,                    XK_a,             togglegaps,             {0} }, // Toggle gaps
	{ MODKEY|Shift,              XK_a,             defaultgaps,            {0} }, // Reset gaps to default

	// Scratch
	SCRATCHKEYSHIFT(             XK_Return,        0 )
	SCRATCHKEYS(                 XK_apostrophe,    1 )
	SCRATCHKEYS(                 XK_r,             2 )

};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
	IPCCOMMAND( focusmon, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( focusstack, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incnmaster, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( killclient, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( quit, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( setlayoutsafe, 1, {ARG_TYPE_PTR} ),
	IPCCOMMAND( setmfact, 1, {ARG_TYPE_FLOAT} ),
	IPCCOMMAND( setstatus, 1, {ARG_TYPE_STR} ),
	IPCCOMMAND( tag, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( tagmon, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( togglebar, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( togglefloating, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( toggletag, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( toggleview, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( view, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( zoom, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( setcfact, 1, {ARG_TYPE_FLOAT} ),
	IPCCOMMAND( cyclelayout, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( togglefakefullscreen, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( floatpos, 1, {ARG_TYPE_STR} ),
	IPCCOMMAND( incnstack, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( rotatelayoutaxis, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( setlayoutaxisex, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( mirrorlayout, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( inplacerotate, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( togglescratch, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( self_restart, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( shiftview, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( shiftviewclients, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( togglesticky, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( switchcol, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( tagnextmonex, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( tagprevmonex, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( togglefullscreen, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( transferall, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( incrgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrigaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrogaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrihgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrivgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrohgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrovgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( togglegaps, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( defaultgaps, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( setgapsex, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( winview, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( xrdb, 1, {ARG_TYPE_NONE} ),
};


