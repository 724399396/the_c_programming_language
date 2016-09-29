#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

struct point makepoint(int x, int y) {
    struct point temp;
    
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int ptinrect(struct point p, struct rect r) {
    return p.x >= r.p1.x && p.x <= r.p2.x
        && p.y >= r.p1.y && p.y <= r.p2.y;
}

struct rect canonrect(struct rect r) {
    struct rect temp;

    temp.p1.x = min(r.p1.x, r.p2.x);
    temp.p2.x = max(r.p1.x, r.p2.x);
    temp.p1.y = min(r.p1.y, r.p2.y);
    temp.p2.y = max(r.p1.y, r.p2.y);
    return temp;
}

void main(void) {}
