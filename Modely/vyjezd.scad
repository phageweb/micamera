$fn = 20;

v = 0.3;
// sirka
s = 100;

difference(){
    cube([s,56,4]);
    translate([5,42.3 / 2 - 3.1,-0.5]) 
    cube([90,2,5]);
}

difference(){
    translate([s/2 - 42.3/ 2,52,0]) cube([42.3,4,12]);
    translate([11.3/2 + 2 + s/2 - 42.3/ 2,56.5,8]) rotate(a = 90, v = [1,0,0]) cylinder(r=1.5 + v,h=5);
    translate([11.3/2 + 29 + s/2 - 42.3/ 2,56.5,8]) rotate(a = 90, v = [1,0,0]) cylinder(r=1.5 + v,h=5);
}

difference(){
    translate([s/2 - 3,42.3 / 2,4]) 
    cube([6,3,8]);
    translate([6/2 + s/2 - 3,5 + 42.3 / 2,4 + 5]) 
    rotate(a = 90, v = [1,0,0]) 
    cylinder(r=1.5 + v,h=6);
}
