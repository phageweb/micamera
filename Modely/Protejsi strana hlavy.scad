$fn = 20;

tloustka = 4;
//vyska v ose y
VvoY = 52;
// vyska motorku
vm = 42.3;
// kruh pro rouru
prumer = 4.5;
vule1 = 0.3;
//prumer der pro sroubek
p = 1.5;
vule = 0.15;
//pozice x pro rouru pro sroubek
x = vm - 30;
// posunuti valce 
tmp = 4.5;


difference(){
    cube([vm,VvoY,tloustka]);
    translate([vm / 2,vm / 2,-0.5]) 
    cylinder(r=prumer + vule1,h=5);
}

difference(){
    translate([0,VvoY,0]) cube([vm,tloustka,12]);
    translate([x/2 + 2,VvoY + tmp,8]) rotate(a = 90, v = [1,0,0]) cylinder(r=p + vule,h=5);
    translate([x/2 + 29,VvoY + tmp,8]) rotate(a = 90, v = [1,0,0]) cylinder(r=p + vule,h=5);
}

translate([vm / 2 + 13,vm / 2 - prumer + vule1 + 0.7 ,0]) cube([5,5,50]);
/*translate([42.3 / 2 - 8 - 10,42.3 / 2 - 3.1,0]) cube([5,5,50]);*/