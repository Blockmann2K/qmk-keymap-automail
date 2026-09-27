// Copyright 2026 Blockmann2K
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Reduce Debounce Time
#define DEBOUNCE 3 // Reduce Input Latency by Filtering Key Chatter Faster Than the Default 5 ms.

// Ensure Polling Rate
#define USB_POLLING_INTERVAL_MS 1 // Force 1000 Hz Polling Rate

// Auto-Shift Configuration
#define AUTO_SHIFT_REPEAT // Enable Keyrepeat Support

#define AUTO_SHIFT_TIMEOUT 200 // Hold Duration in Milliseconds To Send Shifted Key.

// Tap Dance Configuration
#define TAPPING_TERM 150 // Time Duration in Milliseconds To Distinguish Between Tap and Hold.
