$fn = 30;


difference(){
    cube([42.3,52,4]);
    translate([11.3/2,11.3/2,-0.5]) cylinder(r=1.5,h=5);
    translate([11.3/2 + 31,11.3/2 + 31,-0.5]) cylinder(r=1.5,h=5);
    translate([11.3/2,11.3/2 + 31,-0.5]) cylinder(r=1.5,h=5);
    translate([11.3/2 + 31,11.3/2,-0.5]) cylinder(r=1.5,h=5);
    translate([42.3 / 2,42.3 / 2,-0.5]) cylinder(r=11.1,h=5);
}

difference(){
    translate([0,52,0]) cube([42.3,4,15]);
    translate([11.3/2 + 2,56.5,8]) rotate(a = 90, v = [1,0,0]) cylinder(r=1.5,h=5);
    translate([11.3/2 + 29,56.5,8]) rotate(a = 90, v = [1,0,0]) cylinder(r=1.5,h=5);
}
