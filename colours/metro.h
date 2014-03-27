#define NUMCOLORS         6             // need at least 3
static const char colors[NUMCOLORS][ColLast][8] = {
   // border   foreground  background
   { "#eeeeee", "#515151", "#eeeeee" },  // 0 = normal
   { "#00b4ff", "#eeeeee", "#00b4ff" },  // 1 = selected
   { "#ff0054", "#eeeeee", "#ff0054" },  // 2 = urgent/warning
   { "#ff0000", "#ffffff", "#ff0000" },  // 3 = error
   { "#eeeeee", "#00b4ff", "#eeeeee" },  // 4 = blau auf weiss 
   { "#eeeeee", "#ff0054", "#eeeeee" },  // 5 = rot auf weiss 
   // add more here
};
