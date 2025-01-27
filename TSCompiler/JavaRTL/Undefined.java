package JavaRTL;

public class Undefined extends JavaRTL.Void {
    public JavaRTL.Number plus(JavaRTL.Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number plus(JavaRTL.Number other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.String plus(JavaRTL.String other) {
        return new JavaRTL.String(this).plus(other);
    }
    public JavaRTL.Number plus(JavaRTL.Boolean other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number plus(JavaRTL.Void other) {
        return new JavaRTL.Number(this);
    }

    public JavaRTL.Number minus(JavaRTL.Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number minus(JavaRTL.Number other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number minus(JavaRTL.Undefined other) {
        return new JavaRTL.Number(this);
    }

    public JavaRTL.Number mul(JavaRTL.Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number mul(JavaRTL.Number other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number mul(JavaRTL.Undefined other) {
        return new JavaRTL.Number(this);
    }

    public JavaRTL.Number div(JavaRTL.Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number div(JavaRTL.Number other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number div(JavaRTL.Undefined other) {
        return new JavaRTL.Number(this);
    }

    public JavaRTL.Boolean less(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean less(JavaRTL.Number other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean less(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean less(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean less(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean great(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.Number other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean equal(JavaRTL.Null other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean equal(JavaRTL.Number other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean equal(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean equal(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean equal(JavaRTL.Void other) {
        return new JavaRTL.Boolean(true);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean equal(Any other) {
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(true);
        }
        return super.equal(other);
    }

    public JavaRTL.Boolean notEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Number other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.String other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean notEqual(Any other) {
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(false);
        }
        return super.notEqual(other);
    }

    public JavaRTL.Boolean lessEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Number other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean greatEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Number other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    @Override
    public java.lang.String toString() {
        return "undefined";
    }
}
