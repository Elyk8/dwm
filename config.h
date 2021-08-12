/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERM "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 2;   /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 15;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 15;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 24;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 0;  /* vertical padding of bar */
static const int sidepad                 = 0;  /* horizontal padding of bar */
#define ICONSIZE 20    /* icon size */
#define ICONSPACING 5  /* space between icon and title */
static const unsigned int systrayspacing = 3;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_BAR;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static int fakefsindicatortype           = INDICATOR_PLUS;
static int floatfakefsindicatortype      = INDICATOR_PLUS_AND_LARGER_SQUARE;
static int stickyindicatortype           = INDICATOR_BOX_FULL;
static const char *fonts[]               = {
  "JetBrains Mono Nerd Font:heavy:size=11:antialias=true:autohint=true", 
  "Font Awesome:size=10:antialias=true:autohint=true"
  "Twemoji:size=10:antialias=true:autohint=true"
};

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

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
  "shotkey", NULL,
  "xrandr", "-s", "1920x1080", NULL,
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
  RULE(.class = "Brave", .tags = 1 << 2, .isfakefullscreen = 1)
  RULE(.class = "zoom", .tags = 1 << 3, .isfakefullscreen = 1)
  RULE(.class = "Gimp", .tags = 1 << 4)
  RULE(.class = "Firefox", .tags = 1 << 8)
  RULE(.class = "Virt-manager", .tags = 1 << 8, .isfakefullscreen = 1)
  RULE(.class = "discord", .tags = 1 << 7, .isfakefullscreen = 1)
  RULE(.class = "qBittorrent", .tags = 1 << 5)
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
  RULE(.instance = "cheatsheet", .isfloating = 1, .iscentered = 1)
  RULE(.instance = "Mansearch - Viewer", .isfloating = 1, .iscentered = 1)
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
  /* monitor  bar    alignment          widthfunc                drawfunc                clickfunc                name */
  {  0,       1,     BAR_ALIGN_RIGHT,   width_systray,           draw_systray,           click_systray,           "systray" },
  { -1,       0,     BAR_ALIGN_LEFT,    width_tags,              draw_tags,              click_tags,              "tags" },
  { -1,       0,     BAR_ALIGN_LEFT,    width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ 'A',      0,     BAR_ALIGN_RIGHT,   width_status2d,          draw_status2d,          click_statuscmd,         "status2d" },
  { -1,       1,     BAR_ALIGN_NONE,    width_awesomebar,        draw_awesomebar,        click_awesomebar,        "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */


/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */
/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
  /* width change         height change */
  { +scrollsensetivity, 0 },
  { -scrollsensetivity, 0 },
  { 0,            +scrollsensetivity },
  { 0,          -scrollsensetivity },
};

static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
	{ "||=",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
	{ "|||",      flextile,         { -1, -1, NO_SPLIT, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // columns
	{ "==",       flextile,         { -1, -1, NO_SPLIT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // rows
	{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "==#",      flextile,         { -1, -1, SPLIT_HORIZONTAL, TOP_TO_BOTTOM, GAPPLESSGRID, 0, NULL } }, // bstackgrid
	{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
	{ "[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
	{ "[T]",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
	{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
 	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
	{ NULL,       NULL,             {0} },    /* end of layouts marker for cyclelayouts */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
/* #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } */

/* commands */
/* static const char *termcmd[]  = { "st", NULL }; */

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

#include <X11/XF86keysym.h>
static Key keys[] = {
  // KEYBOARD BINDINGS

  /* modifier                   key               function                argument */
  // Tags management
  TAGKEYS(                      XK_1,                                     0) // Tag 1
  TAGKEYS(                      XK_2,                                     1) // Tag 2
  TAGKEYS(                      XK_3,                                     2) // Tag 3
  TAGKEYS(                      XK_4,                                     3) // Tag 4
  TAGKEYS(                      XK_5,                                     4) // Tag 5
  TAGKEYS(                      XK_6,                                     5) // Tag 6
  TAGKEYS(                      XK_7,                                     6) // Tag 7
  TAGKEYS(                      XK_8,                                     7) // Tag 8
  TAGKEYS(                      XK_9,                                     8) // Tag 9

  { MODKEY,                     XK_Tab,           view,                   {0} }, // Toggle back to previously focused tag
  { MODKEY|ShiftMask,           XK_Tab,           shiftview,              { .i = -1 } }, // Backward cycle through tags 

  { MODKEY,                     XK_backslash,     view,                   {0} }, // Toggle back to previously focused tag
  { MODKEY|ShiftMask,           XK_backslash,     shiftview,              { .i = +1 } }, // Forward cycle through tags 

  { MODKEY,                     XK_0,             view,                   {.ui = ~SPTAGMASK } }, // Display all tags
  { MODKEY|ShiftMask,           XK_0,             tag,                    {.ui = ~SPTAGMASK } }, // Make all windows in tag appear on all tags
  
  // Clients management
  { MODKEY,                     XK_h,             focusdir,               {.i = 0 } }, // Focus client to the left
  { MODKEY,                     XK_l,             focusdir,               {.i = 1 } }, // Focus client to the right
  { MODKEY,                     XK_k,             focusdir,               {.i = 2 } }, // Focus client to the up
  { MODKEY,                     XK_j,             focusdir,               {.i = 3 } }, // Focus client to the down

  { MODKEY,                     XK_h,             focusmon,               {.i = -1 } }, // Change focus to previous monitor
  { MODKEY|ShiftMask,           XK_h,             tagmon,                 {.i = -1 } }, // Move tag to previous monitor
  { MODKEY,                     XK_l,             focusmon,               {.i = +1 } }, // Change focus to next monitor
  { MODKEY|ShiftMask,           XK_l,             tagmon,                 {.i = +1 } }, // Move tag to next monitor

	{ MODKEY,                     XK_t,             mirrorlayout,           {0} }, // flip the master and stack areas

	{ MODKEY,                     XK_i,             incnmaster,             {.i = +1 } }, // increase the number of clients in the master area
	{ MODKEY|ShiftMask,           XK_i,             incnstack,              {.i = +1 } }, // increase the number of clients in the primary (first) stack area
	{ MODKEY,                     XK_o,             incnmaster,             {.i = -1 } }, // decrease the number of clients in the master area
	{ MODKEY|ShiftMask,           XK_o,             incnstack,              {.i = -1 } }, // increase the number of clients in the primary (first) stack area

  { MODKEY,                     XK_bracketleft,   setmfact,               {.f = -0.05} }, // Increase master horizontal weight
  { MODKEY,                     XK_bracketright,  setmfact,               {.f = +0.05} }, // Decrease master horizontal weight
  { MODKEY,                     XK_equal,         setcfact,               {.f = +0.25} }, // Increase client vertical weight
  { MODKEY,                     XK_minus,         setcfact,               {.f = -0.25} }, // Decrease client vertical weight

  { MODKEY,                     XK_Left,          focusdir,               {.i = 0 } }, // Focus client to the left
  { MODKEY,                     XK_Right,         focusdir,               {.i = 1 } }, // Focus client to the right
  { MODKEY,                     XK_Up,            focusdir,               {.i = 2 } }, // Focus client to the up
  { MODKEY,                     XK_Down,          focusdir,               {.i = 3 } }, // Focus client to the down

  { MODKEY,                     XK_Left,          focusmon,               {.i = -1 } }, // Change focus to previous monitor
  { MODKEY|ShiftMask,           XK_Left,          tagmon,                 {.i = -1 } }, // Move tag to previous monitor
  { MODKEY,                     XK_Right,         focusmon,               {.i = +1 } }, // Change focus to next monitor
  { MODKEY|ShiftMask,           XK_Right,         tagmon,                 {.i = +1 } }, // Move tag to next monitor

  { MODKEY|ShiftMask,           XK_j,             inplacerotate,          {.i = +2 } }, // Rotate stack and master clockwise
  { MODKEY|ShiftMask,           XK_k,             inplacerotate,          {.i = -2 } }, // Rotate stack and master anticlockwise
  { MODKEY|ShiftMask,           XK_l,             inplacerotate,          {.i = +1} }, // Rotate stack only clockwise
  { MODKEY|ShiftMask,           XK_h,             inplacerotate,          {.i = -1} }, // Rotate stack only anticlockwise

  { MODKEY,                     XK_v,             focusmaster,            {0} }, // Move focus to the master window

  { MODKEY|ShiftMask,           XK_z,             showhideclient,         {0} }, // Hide/show client from the tag

  { MODKEY,                     XK_q,             killclient,             {0} }, // Close the selected client
  { MODKEY|ShiftMask,           XK_q,             killunsel,              {0} }, // Close all but the selected window

  { MODKEY,                     XK_space,         zoom,                   {0} }, // Swap selected stack client with master, or previously selected stack client with the master
  { MODKEY|ShiftMask,           XK_space,         togglefloating,         {0} }, // Toggle window from float to tiling and vice-versa

  // Desktop management
  { MODKEY,                     XK_b,             togglebar,              {0} }, // Toggle dwmbar visibility. Affect all tags

  { MODKEY,                     XK_s,             togglesticky,           {0} }, // Make window appear on all tags

  { MODKEY,                     XK_f,             togglefullscreen,       {0} }, // Toggle focused window fullscreen
  { MODKEY|ShiftMask,           XK_f,             togglefakefullscreen,   {0} }, // Toggle fakefullscreen property of selected client

  // Gaps mamagement
  { MODKEY,                     XK_z,             incrgaps,               {.i = +3 } }, // Increase gap size by 3
  { MODKEY,                     XK_x,             incrgaps,               {.i = -3 } }, // Decrease gap size by 3

  { MODKEY,                     XK_a,             togglegaps,             {0} }, // Toggle gaps
  { MODKEY|ShiftMask,           XK_a,             defaultgaps,            {0} }, // Reset gaps to default
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {


  // MOUSE BINDINGS

  /* click                event mask            button          function        argument */
  // Layout section
  { ClkLtSymbol,          0,                    Button1,        setlayout,      {0} }, // Left click: Set layout to tiling
  { ClkLtSymbol,          0,                    Button3,        setlayout,      {.v = &layouts[5]} }, // Right click: Set monocle layout
  { ClkLtSymbol,          0,                    Button4,        cyclelayout,    {.i = +1 } }, // Mouse wheel up: Forward cycle layout
  { ClkLtSymbol,          0,                    Button5,        cyclelayout,    {.i = -1 } }, // Mouse wheel down: Backward cycle layout
  // Title section
  { ClkWinTitle,          0,                    Button1,        togglewin,      {0} }, // Left click: Select window
  { ClkWinTitle,          0,                    Button3,        showhideclient, {0} }, // Right click: Show/hide the window
  { ClkWinTitle,          0,                    Button2,        zoom,           {0} }, // Move to master from stack, or vice versa
  // dwmblocks status bar, signals depends on individual status bar script
  { ClkStatusText,        0,                    Button1,        sigstatusbar,   {.i = 1} }, // Left click
  { ClkStatusText,        ShiftMask,            Button1,        sigstatusbar,   {.i = 6} }, // Shift left click
  { ClkStatusText,        0,                    Button2,        sigstatusbar,   {.i = 2} }, // Middle click
  { ClkStatusText,        0,                    Button3,        sigstatusbar,   {.i = 3} }, // Right click
  { ClkStatusText,        0,                    Button4,        sigstatusbar,   {.i = 4} }, // Scroll wheel up
  { ClkStatusText,        0,                    Button5,        sigstatusbar,   {.i = 5} }, // Scroll wheel down
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
  // Window management
  { ClkClientWin,         MODKEY,               Button1,        moveorplace,    {.i = 0} },
  { ClkClientWin,         MODKEY,               Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,               Button3,        resizemouse,    {0} },
  { ClkClientWin,         MODKEY,               Button4,        resizemousescroll, {.v = &scrollargs[0]} },
  { ClkClientWin,         MODKEY,               Button5,        resizemousescroll, {.v = &scrollargs[1]} },
  { ClkClientWin,         MODKEY,               Button6,        resizemousescroll, {.v = &scrollargs[2]} },
  { ClkClientWin,         MODKEY,               Button7,        resizemousescroll, {.v = &scrollargs[3]} },
  { ClkClientWin,         MODKEY|ShiftMask,     Button3,        dragcfact,      {0} }, // Vertical resize of individual client window
  { ClkClientWin,         MODKEY|ShiftMask,     Button1,        dragmfact,      {0} }, // Resize master and stack areas
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
	{ "focusurgent",             focusurgent },
	{ "inplacerotate",           inplacerotate },
	{ "setcfact",                setcfact },
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
	{ "xrdb",                    xrdb },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};


