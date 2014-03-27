#define NUMCOLORS         6             // need at least 3
static const char colors[NUMCOLORS][ColLast][8] = {
   // border   foreground  background
   { "#d7c9c0", "#332928", "#d7c9c0" },  // 0 = normal
   { "#ff8080", "#ff8080", "#6b4c47" },  // 1 = selected
   { "#ff0054", "#eeeeee", "#ff0054" },  // 2 = urgent/warning
   { "#ff0000", "#ffffff", "#ff0000" },  // 3 = error
   { "#eeeeee", "#6b4c47", "#d7c9c0" },  // 4 = blau auf weiss 
   { "#eeeeee", "#ff6969", "#d7c9c0" },  // 5 = rot auf weiss 
   // add more here
};
