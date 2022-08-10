#include "process_session_dms.hpp"
int main() {
	process_session_dms *pDms = new process_session_dms;
	if (!pDms) {
		return -1;
	}
	if (!pDms->init()) {
		return -2;
	}
	data_processor *processor = pDms;
	processor->process("ABC", 3);

	return 0;
}