/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERM "st"
#define TERMCLASS "St"

// Define the default attach behaviour here: ATTACHABOVE, ATTACHASIDE, ATTACHBELOW, ATTACHBOTTOM
#define ATTACHABOVE 0
#define ATTACHASIDE 1
#define ATTACHBELOW 0
#define ATTACHBOTTOM 0

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int barborderpx    = 3;   /* border pixel of windows */
static const unsigned int snap           = 2;   /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static int nomodbuttons                  = 1;   /* allow client mouse button bindings that have no modifier */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 24;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 0;  /* vertical padding of bar */
static const int sidepad                 = 0;  /* horizontal padding of bar */
#define ICONSIZE 20    /* icon size */
#define ICONSPACING 3  /* space between icon and title */
static int floatposgrid_x                = 5;  /* float grid columns */
static int floatposgrid_y                = 5;  /* float grid rows */
static const int horizpadbar             = 0;   /* horizontal padding for statusbar */
static const int vertpadbar              = 2;   /* vertical padding for statusbar */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_BOTTOM_BAR;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static int fakefsindicatortype           = INDICATOR_PLUS;
static int floatfakefsindicatortype      = INDICATOR_PLUS_AND_LARGER_SQUARE;
static int stickyindicatortype           = INDICATOR_STICKY;
static const XPoint stickyicon[]         = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb         = {4,8};   /* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */
static const char *fonts[]               = {
	"Iosevka Nerd Font:bold:italic:size=9.5:antialias=true:autohint=true",
	"Noto Color Emoji:size=8.5:antialias=true:autohint=true"
};

static char c000000[]                    = "#000000"; // placeholder value

#include "themes/tokyonight.h"

static const unsigned int baralpha = 0xf0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActTTB]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActLTR]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActMONO]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRID]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRD1]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRD2]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRDM]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActHGRD]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActDWDL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActSPRL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActFloat] = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaTTB]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaLTR]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaMONO]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRID]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRD1]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRD2]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRDM]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaHGRD]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaDWDL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaSPRL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaFloat] = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelTTB]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelLTR]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelMONO]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRID]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRD1]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRD2]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRDM]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelHGRD]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelDWDL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelSPRL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelFloat] = { OPAQUE, baralpha, borderalpha },
};

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
	[SchemeFlexActTTB]   = { titlenormfgcolor, actTTBbgcolor,    actTTBbgcolor,        c000000 },
	[SchemeFlexActLTR]   = { titlenormfgcolor, actLTRbgcolor,    actLTRbgcolor,        c000000 },
	[SchemeFlexActMONO]  = { titlenormfgcolor, actMONObgcolor,   actMONObgcolor,       c000000 },
	[SchemeFlexActGRID]  = { titlenormfgcolor, actGRIDbgcolor,   actGRIDbgcolor,       c000000 },
	[SchemeFlexActGRD1]  = { titlenormfgcolor, actGRD1bgcolor,   actGRD1bgcolor,       c000000 },
	[SchemeFlexActGRD2]  = { titlenormfgcolor, actGRD2bgcolor,   actGRD2bgcolor,       c000000 },
	[SchemeFlexActGRDM]  = { titlenormfgcolor, actGRDMbgcolor,   actGRDMbgcolor,       c000000 },
	[SchemeFlexActHGRD]  = { titlenormfgcolor, actHGRDbgcolor,   actHGRDbgcolor,       c000000 },
	[SchemeFlexActDWDL]  = { titlenormfgcolor, actDWDLbgcolor,   actDWDLbgcolor,       c000000 },
	[SchemeFlexActSPRL]  = { titlenormfgcolor, actSPRLbgcolor,   actSPRLbgcolor,       c000000 },
	[SchemeFlexActFloat] = { titlenormfgcolor, actfloatbgcolor,  actfloatbgcolor,      c000000 },
	[SchemeFlexInaTTB]   = { titlenormfgcolor, normTTBbgcolor,   normTTBbgcolor,       c000000 },
	[SchemeFlexInaLTR]   = { titlenormfgcolor, normLTRbgcolor,   normLTRbgcolor,       c000000 },
	[SchemeFlexInaMONO]  = { titlenormfgcolor, normMONObgcolor,  normMONObgcolor,      c000000 },
	[SchemeFlexInaGRID]  = { titlenormfgcolor, normGRIDbgcolor,  normGRIDbgcolor,      c000000 },
	[SchemeFlexInaGRD1]  = { titlenormfgcolor, normGRD1bgcolor,  normGRD1bgcolor,      c000000 },
	[SchemeFlexInaGRD2]  = { titlenormfgcolor, normGRD2bgcolor,  normGRD2bgcolor,      c000000 },
	[SchemeFlexInaGRDM]  = { titlenormfgcolor, normGRDMbgcolor,  normGRDMbgcolor,      c000000 },
	[SchemeFlexInaHGRD]  = { titlenormfgcolor, normHGRDbgcolor,  normHGRDbgcolor,      c000000 },
	[SchemeFlexInaDWDL]  = { titlenormfgcolor, normDWDLbgcolor,  normDWDLbgcolor,      c000000 },
	[SchemeFlexInaSPRL]  = { titlenormfgcolor, normSPRLbgcolor,  normSPRLbgcolor,      c000000 },
	[SchemeFlexInaFloat] = { titlenormfgcolor, normfloatbgcolor, normfloatbgcolor,     c000000 },
	[SchemeFlexSelTTB]   = { titleselfgcolor,  selTTBbgcolor,    titleselbordercolor,  c000000 },
	[SchemeFlexSelLTR]   = { titleselfgcolor,  selLTRbgcolor,    titleselbordercolor,  c000000 },
	[SchemeFlexSelMONO]  = { titleselfgcolor,  selMONObgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelGRID]  = { titleselfgcolor,  selGRIDbgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelGRD1]  = { titleselfgcolor,  selGRD1bgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelGRD2]  = { titleselfgcolor,  selGRD2bgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelGRDM]  = { titleselfgcolor,  selGRDMbgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelHGRD]  = { titleselfgcolor,  selHGRDbgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelDWDL]  = { titleselfgcolor,  selDWDLbgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelSPRL]  = { titleselfgcolor,  selSPRLbgcolor,   titleselbordercolor,  c000000 },
	[SchemeFlexSelFloat] = { titleselfgcolor,  selfloatbgcolor,  titleselbordercolor,  c000000 },
};


static const char *layoutmenu_cmd = "layoutmenu.sh";

static const char *const autostart[] = {
	"shotkey", NULL,
	"ntfd", NULL,
	"/bin/sh", "-c", "killall -q dwmblocks; sleep 0.2; dwmblocks &", NULL,
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
 *
 * static char *tagicons[][NUMTAGS] = {
 * 	[DEFAULT_TAGS]        = { "", "", "", "", "", "", "", "", "", },
 * 	[ALTERNATIVE_TAGS]    = {"", "", "", "", "", "", "", "", "", },
 * 	[ALT_TAGS_DECORATION] = { "dev", "doc", "obs", "www", "sys", "mat", "pom", "zoom", "dis" },
 * };
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
static char *tagicons[][1] = {
	[DEFAULT_TAGS]        = { " " },
	[ALTERNATIVE_TAGS]    = { " " },
};

static const unsigned int tagalpha[] = { OPAQUE, baralpha };

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
	RULE(.role = "pop-up", .isfloating = 1)
	RULE(.role = "GtkFileChooserDialog", .isfloating = 1, .noswallow = 1)
	RULE(.class = "Soffice", .isfakefullscreen = 1)
	RULE(.class = TERMCLASS, .isterminal = 1, .tags = 1 << 0, .switchtag = 3)
	RULE(.class = "obsidian", .tags = 1 << 2, .switchtag = 3)
	RULE(.class = "VSCodium", .tags = 1 << 2, .switchtag = 3)
	RULE(.class = "Brave-browser", .tags = 1 << 3, .isfakefullscreen = 1, .switchtag = 3)
	RULE(.class = "MATLAB R2021b - academic use", .tags = 1 << 5, .noswallow = 1)
	RULE(.class = "MATLAB R2021b", .tags = 1 << 5, .noswallow = 1)
	RULE(.class = "MATLABWindow", .tags = 1 << 5, .noswallow = 1)
	RULE(.class = "qBittorrent", .tags = 1 << 6, .switchtag = 3)
	RULE(.class = "zoom", .tags = 1 << 7, .isfakefullscreen = 1, .switchtag = 3)
	RULE(.class = "Firefox", .tags = 1 << 8)
	RULE(.class = "discord", .tags = 1 << 8, .isfakefullscreen = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Zathura", .noswallow = 1)
	RULE(.class = "sioyek", .noswallow = 1)
	RULE(.class = "Yad", .isfloating = 1)
	RULE(.class = "Dragon-drag-and-drop", .noswallow = 1)
	RULE(.title = "Event Tester", .noswallow = 1)
	RULE(.instance = "cheatsheet", .isfloating = 1)
	RULE(.instance = "Mansearch - Viewer", .isfloating = 1)
	RULE(.instance = "weatherdisplay", .isfloating = 1)
	RULE(.title = "Picture-in-picture", .isfloating = 1)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1, .isterminal = 1)
	RULE(.instance = "spcalc", .tags = SPTAG(1), .isfloating = 1, .isterminal = 1)
	RULE(.instance = "spfm", .tags = SPTAG(2), .isfloating = 1, .isterminal = 1)
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
static const BarRule barrules[] = {
	/* monitor  bar    alignment               widthfunc                drawfunc                clickfunc                name */
	{ 'A',      0,     BAR_ALIGN_RIGHT,        width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,       0,     BAR_ALIGN_LEFT,         width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ -1,       0,     BAR_ALIGN_LEFT,         width_tags,              draw_tags,              click_tags,              "tags" },
	{ -1,       0,     BAR_ALIGN_NONE,         width_flexwintitle,      draw_flexwintitle,      click_flexwintitle,      "flexwintitle" },
	{  0,       1,     BAR_ALIGN_CENTER,       width_status2d,          draw_status2d,          click_statuscmd,         "status2d" },
	{ -1,       1,     BAR_ALIGN_LEFT,         width_wintitle_floating, draw_wintitle_floating, click_wintitle_floating, "wintitle_floating" },
	{ -1,       1,     BAR_ALIGN_RIGHT_LEFT,   width_wintitle_hidden,   draw_wintitle_hidden,   click_wintitle_hidden,   "wintitle_hidden" },
};

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

#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_v,     ACTION##stack, {.i = PREVSEL } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
/* #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } */

/* commands */
/* static const char *termcmd[]  = { "st", NULL }; */

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
	{
		MODKEY,                    XK_0,             view,                   {.ui = ~SPTAGMASK }
	},                                                                                                                                                                                       // Display all tags
	{ MODKEY|Shift,              XK_0,             tag,                    {.ui = ~SPTAGMASK } }, // Make all windows in current tag appear on all tags

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
	STACKKEYS(MODKEY,                              focus)
	STACKKEYS(MODKEY|ShiftMask,                    push)

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

	{ MODKEY|ControlMask,        XK_o,             reorganizetags,         {0} },

	{ MODKEY,                    XK_Left,          focusmon,               {.i = -1 } }, // Change focus to previous monitor
	{ MODKEY|Shift,              XK_Left,          tagmon,                 {.i = -1 } }, // Move tag to previous monitor
	{ MODKEY,                    XK_Right,         focusmon,               {.i = +1 } }, // Change focus to next monitor
	{ MODKEY|Shift,              XK_Right,         tagmon,                 {.i = +1 } }, // Move tag to next monitor

	{ MODKEY,                    XK_f,             switchcol,              {0} },
	{ MODKEY|Shift,              XK_z,             showhideclient,         {0} }, // Hide/show client from the tag

	{ MODKEY,                    XK_q,             killclient,             {0} }, // Close the selected client
	{ MODKEY|Shift,              XK_q,             killunsel,              {0} }, // Close all but the selected window

	{ MODKEY|Shift,              XK_BackSpace,     self_restart,           {0} }, // restart dusk
	{ MODKEY|Ctrl,               XK_BackSpace,     quit,                   {0} }, // exit dusk

	{ MODKEY,                    XK_m,             zoom,                   {0} }, // Swap selected stack client with master, or previously selected stack client with the master

	{ MODKEY,                    XK_g,             togglefloating,         {0} }, // Toggle window from float to tiling and vice-versa
	{ MODKEY|Shift,              XK_g,             floatpos,               {.v = "50% 50% 80% 80%" } }, // center client and take up 80% of the screen

	// Desktop management
	{ MODKEY,                    XK_b,             togglebar,              {0} }, // Toggle dwmbar visibility. Affect all tags

	{ MODKEY,                    XK_n,             winview,                {0} },

	{ MODKEY|Shift,              XK_n,             togglealttag,           {0} },

	{ MODKEY,                    XK_s,             togglesticky,           {0} }, // Make window appear on all tags


	{ MODKEY,                    XK_space,         setlayout,              {.v = &layouts[12]} },
	// { MODKEY,                    XK_space,         togglefullscreen,       {0} },
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
	// MOUSE BINDINGS

	/* click                event mask            button          function        argument */
	// Layout section
	{ ClkLtSymbol,          0,                    Button1,        layoutmenu,     {0} }, // Left click: Open layout menu (depends on xmenu)
	{ ClkLtSymbol,          0,                    Button3,        setlayout,      {0} }, // Right click: Set layout to tiling
	{ ClkLtSymbol,          0,                    Button4,        cyclelayout,    {.i = +1 } }, // Mouse wheel up: Forward cycle layout
	{ ClkLtSymbol,          0,                    Button5,        cyclelayout,    {.i = -1 } }, // Mouse wheel down: Backward cycle layout
	// Title section
	{ ClkWinTitle,          0,                    Button1,        togglewin,      {0} }, // Left click: Select window
	{ ClkWinTitle,          0,                    Button3,        showhideclient, {0} }, // Right click: Show/hide the window
	{ ClkWinTitle,          0,                    Button2,        zoom,           {0} }, // Move to master from stack, or vice versa
	// dwmblocks status bar, signals depends on individual status bar script
	{ ClkStatusText,        0,                    Button1,        sigstatusbar,   {.i = 1} }, // Left click
	{ ClkStatusText,        Shift,                Button1,        sigstatusbar,   {.i = 6} }, // Shift left click
	{ ClkStatusText,        0,                    Button2,        sigstatusbar,   {.i = 2} }, // Middle click
	{ ClkStatusText,        0,                    Button3,        sigstatusbar,   {.i = 3} }, // Right click
	{ ClkStatusText,        0,                    Button4,        sigstatusbar,   {.i = 4} }, // Scroll wheel up
	{ ClkStatusText,        0,                    Button5,        sigstatusbar,   {.i = 5} }, // Scroll wheel down
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
	// Window management
	{ ClkClientWin,         MODKEY,               Button1,        moveorplace,    {.i = 0} },
	{ ClkClientWin,         MODKEY,               Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,               Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|Shift,         Button3,        dragcfact,      {0} }, // Vertical resize of individual client window
	{ ClkClientWin,         MODKEY|Shift,         Button1,        dragmfact,      {0} }, // Resize master and stack areas
	{ ClkTagBar,            0,                    Button1,        view,           {0} },
	{ ClkTagBar,            0,                    Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,               Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,               Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum                    function */
	{ "focusstack",              focusstack },
	{ "setmfact",                setmfact },
	{ "togglebar",               togglebar },
	{ "incnmaster",              incnmaster },
	{ "togglefloating",          togglefloating },
	{ "focusmon",                focusmon },
	{ "pushstack",               pushstack },
	{ "switchcol",               switchcol },
	{ "incnstack",               incnstack },
	{ "rotatelayoutaxis",        rotatelayoutaxis },
	{ "setlayoutaxisex",         setlayoutaxisex },
	{ "mirrorlayout",            mirrorlayout },
	{ "setcfact",                setcfact },
	{ "transferall",             transferall },
	{ "tagmon",                  tagmon },
	{ "zoom",                    zoom },
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrogaps",               incrogaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "togglegaps",              togglegaps },
	{ "defaultgaps",             defaultgaps },
	{ "setgaps",                 setgapsex },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "toggleview",              toggleview },
	{ "shiftview",               shiftview },
	{ "shiftviewclients",        shiftviewclients },
	{ "self_restart",            self_restart },
	{ "togglesticky",            togglesticky },
	{ "cyclelayout",             cyclelayout },
	{ "toggleviewex",            toggleviewex },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "togglefullscreen",        togglefullscreen },
	{ "togglefakefullscreen",    togglefakefullscreen },
	{ "togglescratch",           togglescratch },
	{ "killclient",              killclient },
	{ "winview",                 winview },
	{ "xrdb",                    xrdb },
	{ "tagnextmonex",            tagnextmonex },
	{ "tagprevmonex",            tagprevmonex },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};
