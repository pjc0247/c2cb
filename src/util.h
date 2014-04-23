#pragma once

#define SAFE_DELETE(m) { \
		if( m != nullptr ){ \
			delete m; \
			m = nullptr; \
		}}
	