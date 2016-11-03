$fn = 20;

vule = 0.3;
//vnejsi prumer
vp = 4;
//vnitrni prumer
vp1 = 2.5;
vyska= 100;

difference(){
    cylinder(r=vp,h=vyska);
    translate([0,0,-0.5])
    cylinder(r=vp1 + vule,h=vyska + 1);
}