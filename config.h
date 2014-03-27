/* See LICENSE file for copyright and license details. */
#include "push.c"
#include <X11/XF86keysym.h>
#include "colours/sola_dark.h"
/* appearance */
static const char font[]            = "-*-stlarch-*-*-*-*-10-*-*-*-*-*-*-*" "," "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */

/* tagging */
static const char *tags[] = { "main", "web", "code", "mail", "etc"};

static const Rule rules[] = {
	/* class		instance    title       tags mask	isfloating   monitor */
	{ "Firefox",	NULL,       NULL,       1 << 1,		False,       -1 },
	{ "Thunderbird",NULL,       NULL,       1 << 3,		False,       -1 },
	{ NULL,			NULL,       "vim",      1 << 2,		False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]  = { "xfce4-terminal", NULL };
static const char *tmenucmd[]  = { "./.scripts/tmenu", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *upvol[] = { "amixer", "set", "Master", "playback", "5%+", NULL};
static const char *downvol[] = { "amixer", "set", "Master", "playback", "5%-", NULL};
static const char *mutevol[] = { "amixer", "set", "Master", "toggle", NULL};
static const char *moncmd[] = { ".scripts/mon", NULL};
static const char *mpctoggle[] = { "mpc", "toggle", NULL};
static const char *mpcnext[] = { "mpc", "next", NULL};
static const char *mpcprev[] = { "mpc", "prev", NULL};
static const char *bridown[] = { "xbacklight", "-dec", "10", NULL};
static const char *briup[] = { "xbacklight", "-inc", "10", NULL};



static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,        	{.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,         	{.v = termcmd } },
	{ MODKEY,                       XK_t,      spawn,		    {.v = tmenucmd} },
	{ MODKEY|ShiftMask,             XK_m,      spawn,		    {.v = moncmd} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_v,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
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
	// Tasten
	{ MODKEY|ShiftMask,				XK_j,		pushdown,		{0} },	
	{ MODKEY|ShiftMask,				XK_k,		pushup,			{0} },
	{ 0,              XF86XK_AudioRaiseVolume, spawn,          {.v = upvol} },
	{ 0,              XF86XK_AudioLowerVolume, spawn,          {.v = downvol} },
	{ 0,              XF86XK_AudioMute, spawn,          {.v = mutevol} },
	{ 0,              XF86XK_AudioPlay, spawn,          {.v = mpctoggle} },
	{ 0,              XF86XK_AudioNext, spawn,          {.v = mpcnext} },
	{ 0,              XF86XK_AudioPrev, spawn,          {.v = mpcprev} },
	{ 0,              XF86XK_MonBrightnessDown, spawn,  {.v = bridown} },
	{ 0,              XF86XK_MonBrightnessUp, spawn,  	{.v = briup} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
//	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
//	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

