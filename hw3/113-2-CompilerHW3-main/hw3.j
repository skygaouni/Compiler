.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
	.limit stack 100
	.limit locals 100
	ldc 1
	istore 0
	L_if_true_0:
	iload 0
	ldc 101
	isub
	iflt L_cmp_0
	iconst_0
	goto L_cmp_end_0
	L_cmp_0:
	iconst_1
	L_cmp_end_0:
	ifeq L_if_false_0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 1
	iload 0
	swap
	iadd
	istore 0
	goto L_if_true_0
	L_if_false_0:
	return
.end method
