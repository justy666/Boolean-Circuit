/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 * Time-stamp: <Tue Jul 17 16:02:29 EDT 2018 ferguson>
 */
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"

/**
 * Two AND gates connected to make a 3-input AND circuit.
 */
// static Circuit *and3_Circuit()
// {
// 	Boolean *x = new_Boolean(false);
// 	Boolean *y = new_Boolean(false);
// 	Boolean *z = new_Boolean(false);
// 	Boolean **inputs = new_Boolean_array(3);
// 	inputs[0] = x;
// 	inputs[1] = y;
// 	inputs[2] = z;

// 	Boolean *out = new_Boolean(false);
// 	Boolean **outputs = new_Boolean_array(1);
// 	outputs[0] = out;

// 	Gate *A1 = new_AndGate();
// 	Gate *A2 = new_AndGate();
// 	Gate **gates = new_Gate_array(2);
// 	gates[0] = A1;
// 	gates[1] = A2;

// 	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 2, gates);
// 	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
// 	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
// 	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
// 	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
// 	Circuit_connect(circuit, Gate_getOutput(A2), out);
// 	return circuit;
// }

//create circuit (a)
static Circuit *Circuit1()
{
	Boolean *x = new_Boolean(false);
	Boolean *y = new_Boolean(false);
	Boolean *z = new_Boolean(false);
	Boolean **inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean *out = new_Boolean(false);
	Boolean **outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate *A1 = new_AndGate();
	Gate *A2 = new_NorGate();
	Gate *A3 = new_OrGate();
	Gate **gates = new_Gate_array(3);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 3, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
	Circuit_connect(circuit, y, Gate_getInput(A2, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), out);
	return circuit;
}

//create circuit (b)
static Circuit *Circuit2()
{
	Boolean *x = new_Boolean(false);
	Boolean *y = new_Boolean(false);
	Boolean *z = new_Boolean(false);
	Boolean **inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean *out = new_Boolean(false);
	Boolean **outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate *A1 = new_Inverter();
	Gate *A2 = new_OrGate();
	Gate *A3 = new_AndGate();
	Gate *A4 = new_AndGate();
	Gate **gates = new_Gate_array(4);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;
	gates[3] = A4;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 4, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, y, Gate_getInput(A3, 1));
	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
	Circuit_connect(circuit, y, Gate_getInput(A2, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A4, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A4, 0));
	Circuit_connect(circuit, Gate_getOutput(A4), out);
	return circuit;
}

//create circuit (c)
static Circuit *Circuit3()
{
	Boolean *x = new_Boolean(false);
	Boolean *y = new_Boolean(false);
	Boolean *z = new_Boolean(false);
	Boolean **inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean *out = new_Boolean(false);
	Boolean **outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate *A1 = new_Inverter();
	Gate *A2 = new_Inverter();
	Gate *A3 = new_AndGate();
	Gate *A4 = new_NandGate();
	Gate *A5 = new_OrGate();
	Gate **gates = new_Gate_array(5);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;
	gates[3] = A4;
	gates[4] = A5;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 5, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, y, Gate_getInput(A3, 1));
	Circuit_connect(circuit, z, Gate_getInput(A2, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A4, 1));
	Circuit_connect(circuit, y, Gate_getInput(A4, 0));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A5, 0));
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(A5, 1));
	Circuit_connect(circuit, Gate_getOutput(A5), out);
	return circuit;
}

static char *b2s(bool b)
{
	return b ? "T" : "F";
}

static void test3In1Out(Circuit *circuit, bool in0, bool in1, bool in2)
{
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
}

//extra credit part1 (one-bit adder)//
static char *b2i(bool b)
{
	return b ? "T" : "F";
}

static void test3In2Out(Circuit *circuit, bool in0, bool in1, bool in2)
{
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool out1 = Circuit_getOutput(circuit, 0);
	bool out2 = Circuit_getOutput(circuit, 1);
	printf("%s %s %s -> %s %s\n", b2i(in0), b2i(in1), b2i(in2), b2i(out1), b2i(out2));
}

//One function that test all the combinations of inputs
static void testall(Circuit *cir, bool b, int n)
{
	//3 in 1 out
	if ((Circuit_numInputs(cir) == 3) && (b == false))
	{
		if (n == 8)
		{
			return;
		}
		test3In1Out(cir, (n >> 2) & 1, (n >> 1) & 1, (n >> 0) & 1);
		testall(cir, b, n + 1);
	}
	//3 in 2 out
	else if ((Circuit_numInputs(cir) == 3) && (b == true))
	{
		if (n == 8)
		{
			return;
		}
		test3In2Out(cir, (n >> 2) & 1, (n >> 1) & 1, (n >> 0) & 1);
		testall(cir, b, n + 1);
	}
}

//create circuit one bit adder
static Circuit *onebitadder()
{
	Boolean *x = new_Boolean(false);
	Boolean *y = new_Boolean(false);
	Boolean *z = new_Boolean(false);
	Boolean **inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;
	Boolean *out1 = new_Boolean(false);
	Boolean *out2 = new_Boolean(false);
	Boolean **outputs = new_Boolean_array(2);
	outputs[0] = out1;
	outputs[1] = out2;

	Gate *A1 = new_Inverter();
	Gate *A2 = new_Inverter();
	Gate *A3 = new_Inverter();
	Gate *A4 = new_And3Gate();
	Gate *A5 = new_And3Gate();
	Gate *A6 = new_And3Gate();
	Gate *A7 = new_And3Gate();
	Gate *A8 = new_And3Gate();
	Gate *A9 = new_And3Gate();
	Gate *A10 = new_And3Gate();
	Gate *A11 = new_Or4Gate();
	Gate *A12 = new_Or4Gate();
	Gate **gates = new_Gate_array(12);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;
	gates[3] = A4;
	gates[4] = A5;
	gates[5] = A6;
	gates[6] = A7;
	gates[7] = A8;
	gates[8] = A9;
	gates[9] = A10;
	gates[10] = A11;
	gates[11] = A12;

	Circuit *circuit = new_Circuit(3, inputs, 2, outputs, 12, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A2, 0));
	Circuit_connect(circuit, z, Gate_getInput(A3, 0));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A4, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A4, 1));
	Circuit_connect(circuit, z, Gate_getInput(A4, 2));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A5, 0));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A5, 1));
	Circuit_connect(circuit, y, Gate_getInput(A5, 2));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A6, 0));
	Circuit_connect(circuit, x, Gate_getInput(A7, 0));
	Circuit_connect(circuit, y, Gate_getInput(A6, 1));
	Circuit_connect(circuit, z, Gate_getInput(A6, 2));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A7, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A7, 2));
	Circuit_connect(circuit, x, Gate_getInput(A8, 0));
	Circuit_connect(circuit, z, Gate_getInput(A8, 1));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A8, 2));
	Circuit_connect(circuit, x, Gate_getInput(A9, 0));
	Circuit_connect(circuit, y, Gate_getInput(A9, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A9, 2));
	Circuit_connect(circuit, x, Gate_getInput(A10, 0));
	Circuit_connect(circuit, y, Gate_getInput(A10, 1));
	Circuit_connect(circuit, z, Gate_getInput(A10, 2));
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(A12, 0));
	Circuit_connect(circuit, Gate_getOutput(A8), Gate_getInput(A12, 1));
	Circuit_connect(circuit, Gate_getOutput(A9), Gate_getInput(A12, 2));
	Circuit_connect(circuit, Gate_getOutput(A10), Gate_getInput(A12, 3));
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(A11, 0));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(A11, 1));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(A11, 2));
	Circuit_connect(circuit, Gate_getOutput(A10), Gate_getInput(A11, 3));
	Circuit_connect(circuit, Gate_getOutput(A11), out1);
	Circuit_connect(circuit, Gate_getOutput(A12), out2);
	return circuit;
}

int main(int argc, char **argv)
{
	//circuit (a)
	Circuit *circuitA = Circuit1();
	printf("********The circuit A********\n");
	Circuit_dump(circuitA);
	printf("\n");
	testall(circuitA, false, 0);
	Circuit_free(circuitA);

	//circuit (b)
	Circuit *circuitB = Circuit2();
	printf("********The circuit B********\n");
	Circuit_dump(circuitB);
	printf("\n");
	testall(circuitB, false, 0);
	Circuit_free(circuitB);

	//circuit (c)
	Circuit *circuitC = Circuit3();
	printf("********The circuit C********\n");
	Circuit_dump(circuitC);
	printf("\n");
	testall(circuitC, false, 0);
	Circuit_free(circuitC);

	//extra credit part1
	Circuit *circuitD = onebitadder();
	printf("********The extra credit part1 circuit ONE-BIT ADDER********\n");
	Circuit_dump(circuitD);
	printf("\n");
	testall(circuitD, true, 0);
	Circuit_free(circuitD);
}
