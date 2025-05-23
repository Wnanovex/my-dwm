/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "MesloLGS Nerd Font:size=12" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_purple[]        = "#a151d3";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_purple  },
	[SchemeSel]  = { col_gray4, col_purple,  col_purple  },
};

static const char *const autostart[] = {
        //"st", NULL,
	"sxhkd", NULL,
	"slstatus", NULL,
	"dunst", NULL,
	"nitrogen", "--restore", NULL,
	"sh", "-c", "picom --experimental-backends -b", NULL,
	"sh", "-c", "xautolock -time 20 -locker \"systemctl suspend\"" ,NULL,
	"sh", "-c", "xautolock -time 5 -locker \"betterlockscreen -l\"" ,NULL,
	NULL /* terminate */
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 }
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_purple, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	//{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },// start demenu
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } }, // open terminal
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} }, // show and hide top bar
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } }, // tranform by up stack window
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, // tranform by down stack window
	{ MODKEY|ShiftMask,             XK_j,      pushdown,       {0} }, // tranform by up stack window without master
        { MODKEY|ShiftMask,             XK_k,      pushup,         {0} }, // tranform by down stack window without master
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } }, // increase master or add another master
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } }, // decrease master or remove another master
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} }, // increase area of master
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} }, // decrease area of master
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} }, // transform normal window to master window
	{ MODKEY,                       XK_Tab,    view,           {0} }, // switch from current tab to last tab
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} }, // close window
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // tiling mode
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, // float mode
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, // monocle mode
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} }, // switch layout
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} }, // switch layout
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, // display all tags in one tag
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, // display all tags in one tag
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } }, // switch layout
	{ MODKEY|ShiftMask|ControlMask, XK_period, focusmon,       {.i = +1 } }, // switch layout
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } }, // move one window to any monitor
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } }, // move one window to any monitor
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } }, // add gaps 
        { MODKEY,                       XK_equal,  setgaps,        {.i = +1 } }, // minus gaps
        { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } }, // set default gaps	
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

