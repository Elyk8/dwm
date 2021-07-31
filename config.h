/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERM "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 15;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 15;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 30;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 15;  /* vertical padding of bar */
static const int sidepad                 = 15;  /* horizontal padding of bar */
#define ICONSIZE 20    /* icon size */
#define ICONSPACING 5  /* space between icon and title */
static const unsigned int systrayspacing = 3;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static int stickyindicatortype           = INDICATOR_BOTTOM_BAR_SLIM;
static const char *fonts[]               = {
  "monospace:size=10:antialias=true:autohint=true", 
  "Twemoji:size=9:antialias=true:autohint=true"
};

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#D8DEE9";
static char normbgcolor[]                = "#1b1b1b";
static char normbordercolor[]            = "#1b1b1b";
static char normfloatcolor[]             = "#569CD6";

static char selfgcolor[]                 = "#ECEFF4";
static char selbgcolor[]                 = "#3B4252";
static char selbordercolor[]             = "#ECEFF4";
static char selfloatcolor[]              = "#569CD6";

static char titlenormfgcolor[]           = "#D8DEE9";
static char titlenormbgcolor[]           = "#1b1b1b";
static char titlenormbordercolor[]       = "#3B4252";
static char titlenormfloatcolor[]        = "#569CD6";

static char titleselfgcolor[]            = "#ECEFF4";
static char titleselbgcolor[]            = "#3B4252";
static char titleselbordercolor[]        = "#3B4252";
static char titleselfloatcolor[]         = "#569CD6";

static char tagsnormfgcolor[]            = "#D8DEE9";
static char tagsnormbgcolor[]            = "#1b1b1b";
static char tagsnormbordercolor[]        = "#3B4252";
static char tagsnormfloatcolor[]         = "#569CD6";

static char tagsselfgcolor[]             = "#ECEFF4";
static char tagsselbgcolor[]             = "#3B4252";
static char tagsselbordercolor[]         = "#3B4252";
static char tagsselfloatcolor[]          = "#569CD6";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

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
	"st", NULL,
	"dwmblocks", NULL,
	NULL /* terminate */
};


const char *spcmd1[] = {TERM, "-n", "spterm", "-g", "100x25", NULL};
const char *spcmd2[] = {TERM, "-n", "spcalc", "-f", "monospace:size=12", "-g", "50x20", "-e", "bc", "-lq", NULL};
const char *spcmd3[] = {TERM, "-n", "spmusic", "-g", "100x25", "-e", "ncmpcpp", " ", NULL};

static Sp scratchpads[] = {
  /* name          cmd  */
  {"spterm",      spcmd1},
  {"spcalc",      spcmd2},
  {"spmusic",     spcmd3},
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
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
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
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Brave", .tags = 1 << 2)
	RULE(.class = "zoom", .tags = 1 << 3)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "discord", .tags = 1 << 7)
	RULE(.class = "Firefox", .tags = 1 << 8)
	RULE(.class = "Zathura", .noswallow = 1)
	RULE(.class = "MATLAB R2021a - academic use", .tags = 1 << 4, .noswallow = 1)
	RULE(.class = "MATLAB R2021a", .tags = 1 << 4, .noswallow = 1)
	RULE(.class = "MATLABWindow", .tags = 1 << 4, .noswallow = 1)
	RULE(.class = "Dragon-drag-and-drop", .noswallow = 1, .iscentered = 1)
	RULE(.title = "Event Tester", .noswallow = 1)
	RULE(.class = TERMCLASS, .isterminal = 1)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.instance = "spcalc", .tags = SPTAG(1), .isfloating = 1)
	RULE(.instance = "spmusic", .tags = SPTAG(2), .isfloating = 1)
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
	/* monitor  bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{  0,       0,     BAR_ALIGN_LEFT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{  0,       0,     BAR_ALIGN_RIGHT,   width_status,            draw_status,            click_statuscmd,         "status" },
	{ -1,       0,     BAR_ALIGN_NONE,   width_awesomebar,        draw_awesomebar,        click_awesomebar,        "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nmaxmaster  = 3;    /* maximum number of clients allowed in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */


/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */
/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
	/* width change         height change */
	{ +scrollsensetivity,	0 },
	{ -scrollsensetivity,	0 },
	{ 0, 				  	+scrollsensetivity },
	{ 0, 					-scrollsensetivity },
};

static const Layout layouts[] = {
	/* symbol     arrange function */
  { "[]=",      tile },                         /* Default: Master on left, slaves on right */
  { "TTT",      bstack },                       /* Master on top, slaves on bottom */
  { "[@]",      spiral },                       /* Fibonacci spiral */
  { "[\\]",     dwindle },                      /* Decreasing in size right and leftward */
  { "[D]",      deck },                         /* Master on left, slaves in monocle-like mode on right */
  { "[M]",      monocle },                      /* All windows on top of eachother */
  { "|M|",      centeredmaster },               /* Master in middle, slaves on sides */
  { ">M>",      centeredfloatingmaster },       /* Same but master floats */
  { "><>",      NULL },                         /* no layout function means floating behavior */
  { NULL,       NULL },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "st", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,          inplacerotate,          {.i = +2 } }, // same as rotatestack
	{ MODKEY|ShiftMask,             XK_k,          inplacerotate,          {.i = -2 } }, // same as reotatestack
	{ MODKEY|ShiftMask,             XK_l,          inplacerotate,          {.i = +1} },
	{ MODKEY|ShiftMask,             XK_h,          inplacerotate,          {.i = -1} },
	{ MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
  { MODKEY|ShiftMask,             XK_Return,     togglescratch,          {.ui = 0} },
  { MODKEY,                       XK_BackSpace,  spawn,                  SHCMD("rofipowermenu") },
  { MODKEY|ShiftMask,             XK_BackSpace,  spawn,                  SHCMD("rofipowermenu") },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
  { MODKEY,                       XK_o,          incnmaster,             {.i = +1 } },
  { MODKEY|ShiftMask,             XK_o,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ControlMask,           XK_k,          setcfact,               {.f = +0.25} },
	{ MODKEY|ControlMask,           XK_j,          setcfact,               {.f = -0.25} },
  { MODKEY,                       XK_space,      zoom,                   {0} },
  { MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
  { MODKEY,                       XK_z,          incrgaps,               {.i = +3 } },
	{ MODKEY|ShiftMask,             XK_z,          showhideclient,         {0} },
  { MODKEY,                       XK_x,          incrgaps,               {.i = -3 } },
	{ MODKEY|ShiftMask,             XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY,                       XK_a,          togglegaps,             {0} },
	{ MODKEY|ShiftMask,             XK_a,          defaultgaps,            {0} },
  { MODKEY,                       XK_Tab,        spawn,                  SHCMD("skippy-xd") },
	{ MODKEY|ShiftMask,             XK_Tab,        shiftview,              { .i = -1 } },
  { MODKEY,                       XK_backslash,  view,                   {0} },
	{ MODKEY|ShiftMask,             XK_backslash,  shiftview,              { .i = +1 } },
  { MODKEY,                       XK_apostrophe, togglescratch,          {.ui = 1} },
  /* { MODKEY|ShiftMask,               XK_apostrophe,         spawn,               SHCMD("") }, */
  { MODKEY,                       XK_q,          killclient,             {0} },
  { MODKEY|ShiftMask,             XK_q,          killunsel,              {0} },
  { MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} }, /* tile */
  { MODKEY|ShiftMask,             XK_t,          setlayout,              {.v = &layouts[1]} }, /* bstack */
  { MODKEY,                       XK_y,          setlayout,              {.v = &layouts[2]} }, /* spiral */
  { MODKEY|ShiftMask,             XK_y,          setlayout,              {.v = &layouts[3]} }, /* dwindle */
  { MODKEY,                       XK_u,          setlayout,              {.v = &layouts[4]} }, /* deck */
  { MODKEY|ShiftMask,             XK_u,          setlayout,              {.v = &layouts[5]} }, /* monocle */
  { MODKEY,                       XK_i,          setlayout,              {.v = &layouts[6]} }, /* centeredmaster */
  { MODKEY|ShiftMask,             XK_i,          setlayout,              {.v = &layouts[7]} }, /* centeredfloatingmaster */
  { MODKEY,                       XK_f,          togglefullscreen,       {0} },
  { MODKEY|ShiftMask,             XK_f,          setlayout,              {.v = &layouts[8]} },
	{ MODKEY,                       XK_s,          togglesticky,           {0} },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
	{ MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
  /* Applications shortcuts */
  { MODKEY,                       XK_w,          spawn,                  SHCMD("bookmarksurf") },
  { MODKEY|ShiftMask,             XK_w,          spawn,                  SHCMD("$BROWSER") },
  { MODKEY,                       XK_e,          spawn,                  SHCMD(TERM " -e neomutt ; pkill -RTMIN+$(awk '/sb-mailbox/ {print $4}' ~/.local/src/dwmblocks/config.h) dwmblocks") },
  { MODKEY|ShiftMask,             XK_e,          spawn,                  SHCMD(TERM " -e abook") },
  { MODKEY,                       XK_r,          spawn,                  SHCMD(TERM " -e lf-run") },
  { MODKEY|ShiftMask,             XK_r,          spawn,                  SHCMD(TERM " -e gotop") },
  { MODKEY,                       XK_v,          spawn,                  SHCMD("start-conky") },
  { MODKEY|ShiftMask,             XK_v,          spawn,                  SHCMD("killall conky") },
  /* Music player */
  { MODKEY,                       XK_minus,      spawn,                  SHCMD("mpc volume -3; kill -35 $(pidof dwmblocks)") },
  { MODKEY|ShiftMask,             XK_minus,      spawn,                  SHCMD("mpc volume -12; kill -35 $(pidof dwmblocks)") },
  { MODKEY,                       XK_equal,      spawn,                  SHCMD("mpc volume +3; kill -35 $(pidof dwmblocks)") },
  { MODKEY|ShiftMask,             XK_equal,      spawn,                  SHCMD("mpc volume +12; kill -35 $(pidof dwmblocks)") },
  { MODKEY,                       XK_p,            spawn,                SHCMD("mpc toggle") },
  { MODKEY|ShiftMask,             XK_p,            spawn,                SHCMD("mpc pause ; pauseallmpv") },
  { MODKEY,                       XK_bracketleft,  spawn,                SHCMD("mpc seek -10") },
  { MODKEY|ShiftMask,             XK_bracketleft,  spawn,                SHCMD("mpc seek -60") },
  { MODKEY,                       XK_bracketright, spawn,                SHCMD("mpc seek +10") },
  { MODKEY|ShiftMask,             XK_bracketright, spawn,                SHCMD("mpc seek +60") },
  { MODKEY,                       XK_comma,      spawn,                  SHCMD("mpc prev") },
  { MODKEY|ShiftMask,             XK_comma,      spawn,                  SHCMD("mpc seek 0%") },
  { MODKEY,                       XK_period,     spawn,                  SHCMD("mpc next") },
  { MODKEY|ShiftMask,             XK_period,     spawn,                  SHCMD("mpc repeat") },
  { MODKEY,                       XK_c,          spawn,                  SHCMD("rofigreenclip") },
  //{ MODKEY|ShiftMask,             XK_c,          spawn,                  SHCMD("") },
  { MODKEY,                       XK_d,          spawn,                  SHCMD("j4-dmenu-desktop --dmenu=\"dmenu -c -X 15 -Y 15 -W 1884 -l 0\"") },
  { MODKEY|ShiftMask,             XK_d,          spawn,                  SHCMD("rofi-pass") },
  { MODKEY,                       XK_m,          togglescratch,          {.ui = 2} },
  { MODKEY|ShiftMask,             XK_m,          spawn,                  SHCMD("mic-toggle") },
  { MODKEY,                       XK_n,          spawn,                  SHCMD("dmenunotes") },
  { MODKEY|ShiftMask,             XK_n,          spawn,                  SHCMD(TERM " -e newsboat; pkill -RTMIN+11 dwmblocks") },

  { MODKEY,                       XK_Left,       focusmon,               {.i = -1 } },
  { MODKEY|ShiftMask,             XK_Left,       tagmon,                 {.i = -1 } },
  { MODKEY,                       XK_Right,      focusmon,               {.i = +1 } },
  { MODKEY|ShiftMask,             XK_Right,      tagmon,                 {.i = +1 } },

  { MODKEY,                       XK_Page_Up,    shiftview,              { .i = -1 } },
  { MODKEY,                       XK_Page_Down,  shiftview,              { .i = +1 } },

  { MODKEY,                       XK_F1,         spawn,                  SHCMD("feh --bg-fill --no-fehbg --random ~/Pics/wallpapers/*") },
  { MODKEY,                       XK_F2,         spawn,                  SHCMD("dmenuunicode") },
  { MODKEY,                       XK_F3,         spawn,                  SHCMD("bookmarker") },
  { MODKEY,                       XK_F4,         spawn,                  SHCMD("pavucontrol; kill -40 $(pidof dwmblocks)") },
  /* { MODKEY,                       XK_F5,        xrdb,                {.v = NULL } }, */
  /* { MODKEY,                       XK_F6,        spawn,                  SHCMD("") }, */
  { MODKEY,                       XK_F7,         spawn,                  SHCMD("flameshot gui -p ~/Pics/screenshots") },
  { MODKEY|ShiftMask,             XK_F7,         spawn,                  SHCMD("flameshot full -p ~/Pics/screenshots") },
  { MODKEY,                       XK_F8,         spawn,                  SHCMD("mw -Y && kill -38 $(pidof dwmblocks)") },
  { MODKEY,                       XK_F9,         spawn,                  SHCMD("dmenumount") },
  { MODKEY,                       XK_F10,        spawn,                  SHCMD("dmenuumount") },
  { MODKEY,                       XK_F11,        spawn,                  SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --profile=low-latency --untimed --vf=hflip --no-keepaspect-window --panscan=1 --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
  { MODKEY,                       XK_F12,        spawn,                  SHCMD("remaps && notify-send \\\"⌨️ Keyboard remapping...\\\" \\\"Re-running keyboard defaults for any newly plugged-in keyboards.\\\"") },

  { 0,                            XK_Print,      spawn,                  SHCMD("flameshot gui -p ~/Pics/screenshots") },
  { ShiftMask,                    XK_Print,      spawn,                  SHCMD("flameshot full -p ~/Pics/screenshots") },

  { 0, XF86XK_AudioMute,          spawn,         SHCMD("pamixer -t; kill -40 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioRaiseVolume,   spawn,         SHCMD("pamixer --allow-boost -i 3; kill -40 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioLowerVolume,   spawn,         SHCMD("pamixer --allow-boost -d 3; kill -40 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioPrev,          spawn,         SHCMD("mpc prev") },
  { 0, XF86XK_AudioNext,          spawn,         SHCMD("mpc next") },
  { 0, XF86XK_AudioPause,         spawn,         SHCMD("mpc pause") },
  { 0, XF86XK_AudioPlay,          spawn,         SHCMD("mpc play") },
  { 0, XF86XK_AudioStop,          spawn,         SHCMD("mpc stop") },
  { 0, XF86XK_AudioRewind,        spawn,         SHCMD("mpc seek -10") },
  { 0, XF86XK_AudioForward,       spawn,         SHCMD("mpc seek +10") },
  { 0, XF86XK_AudioMedia,         spawn,         SHCMD(TERM " -e ncmpcpp") },
  { 0, XF86XK_AudioMicMute,       spawn,         SHCMD("mic-toggle") },
  { 0, XF86XK_PowerOff,           spawn,         SHCMD("rofipowermenu") },
  { 0, XF86XK_Calculator,         spawn,         SHCMD(TERM " -e bc -l") },
  { 0, XF86XK_Sleep,              spawn,         SHCMD("sudo -A zzz") },
  { 0, XF86XK_WWW,                spawn,         SHCMD("$BROWSER") },
  { 0, XF86XK_DOS,                spawn,         SHCMD(TERM) },
  { 0, XF86XK_ScreenSaver,        spawn,         SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
  { 0, XF86XK_TaskPane,           spawn,         SHCMD(TERM " -e gotop") },
  { 0, XF86XK_Mail,               spawn,         SHCMD(TERM " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
  { 0, XF86XK_MyComputer,         spawn,         SHCMD(TERM " -e lf-run") },
  /* { 0, XF86XK_Battery,           spawn,         SHCMD("") }, */
  { 0, XF86XK_Launch1,            spawn,         SHCMD("xset dpms force off") },
  { 0, XF86XK_TouchpadToggle,     spawn,         SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
  { 0, XF86XK_TouchpadOff,        spawn,         SHCMD("synclient TouchpadOff=1") },
  { 0, XF86XK_TouchpadOn,         spawn,         SHCMD("synclient TouchpadOff=0") },
  { 0, XF86XK_MonBrightnessUp,    spawn,         SHCMD("xbacklight -inc 2 ; kill -42 $(pidof dwmblocks)") },
  { 0, XF86XK_MonBrightnessDown,  spawn,         SHCMD("xbacklight -dec 2 ; kill -42 $(pidof dwmblocks)") },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
  { ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1} },        // left click
  { ClkStatusText,        ShiftMask,           Button1,        sigstatusbar,   {.i = 6} },        // shift left click
  { ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2} },        // middle click
  { ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3} },        // right click
  { ClkStatusText,        0,                   Button4,        sigstatusbar,   {.i = 4} },        // scroll wheel up
  { ClkStatusText,        0,                   Button5,        sigstatusbar,   {.i = 5} },        // scroll wheel down
	/* { ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} }, */
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
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY,              Button4,        resizemousescroll, {.v = &scrollargs[0]} },
	{ ClkClientWin,         MODKEY,              Button5,        resizemousescroll, {.v = &scrollargs[1]} },
	{ ClkClientWin,         MODKEY,              Button6,        resizemousescroll, {.v = &scrollargs[2]} },
	{ ClkClientWin,         MODKEY,              Button7,        resizemousescroll, {.v = &scrollargs[3]} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};



