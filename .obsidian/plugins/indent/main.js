"use strict";
var __defProp = Object.defineProperty;
var __getOwnPropDesc = Object.getOwnPropertyDescriptor;
var __getOwnPropNames = Object.getOwnPropertyNames;
var __hasOwnProp = Object.prototype.hasOwnProperty;
var __export = (target, all) => {
  for (var name in all)
    __defProp(target, name, { get: all[name], enumerable: true });
};
var __copyProps = (to, from, except, desc) => {
  if (from && typeof from === "object" || typeof from === "function") {
    for (let key of __getOwnPropNames(from))
      if (!__hasOwnProp.call(to, key) && key !== except)
        __defProp(to, key, { get: () => from[key], enumerable: !(desc = __getOwnPropDesc(from, key)) || desc.enumerable });
  }
  return to;
};
var __toCommonJS = (mod) => __copyProps(__defProp({}, "__esModule", { value: true }), mod);

// main.ts
var main_exports = {};
__export(main_exports, {
  default: () => IndentPlugin
});
module.exports = __toCommonJS(main_exports);
var import_obsidian = require("obsidian");
var DEFAULT_SETTINGS = {
  enabled: true
};
var LEGACY_MARKERS = /* @__PURE__ */ new Set(["\xA0", "\u2009"]);
var MARKER = "\u200C";
function isFenceLine(text) {
  return /^\s{0,3}(?:```|~~~)/.test(text);
}
function isMathFenceLine(text) {
  return /^\s{0,3}(?:\$\$|\\\[|\\\])\s*$/.test(text);
}
function looksLikeListOrQuote(text) {
  return /^(?:[-+*]\s+|\d+[.)]\s+|>\s+)/.test(text);
}
function stripLeadingMarker(text) {
  const first = text[0];
  if (!first) return { text, hadMarker: false };
  if (first === MARKER || LEGACY_MARKERS.has(first)) {
    return { text: text.slice(1), hadMarker: true };
  }
  return { text, hadMarker: false };
}
function normalizeIndentedLines(editor) {
  let insideFence = false;
  let insideMath = false;
  let frontmatterEnd = -1;
  const lineCount = editor.lineCount();
  if (lineCount > 0 && editor.getLine(0).trim() === "---") {
    for (let i = 1; i < lineCount; i++) {
      if (editor.getLine(i).trim() === "---") {
        frontmatterEnd = i;
        break;
      }
    }
  }
  for (let line = 0; line < lineCount; line++) {
    const original = editor.getLine(line);
    const stripped = stripLeadingMarker(original);
    const text = stripped.text;
    if (frontmatterEnd > 0 && line <= frontmatterEnd) {
      if (stripped.hadMarker && text !== original) editor.setLine(line, text);
      continue;
    }
    if (isFenceLine(text)) {
      insideFence = !insideFence;
      continue;
    }
    if (isMathFenceLine(text)) {
      insideMath = !insideMath;
      continue;
    }
    if (insideFence || insideMath) continue;
    const match = text.match(/^[\t ]+/);
    const leading = match ? match[0] : "";
    const rest = match ? text.slice(leading.length) : text;
    const hasTab = leading.includes("	");
    const isListOrQuote = looksLikeListOrQuote(rest);
    if (!text.trim()) {
      if (stripped.hadMarker && text !== original) editor.setLine(line, text);
      continue;
    }
    if (isListOrQuote || isFenceLine(rest)) {
      if (stripped.hadMarker && text !== original) editor.setLine(line, text);
      continue;
    }
    if (!match || !hasTab && leading.length < 4) {
      if (stripped.hadMarker && text !== original) editor.setLine(line, text);
      continue;
    }
    const updated = MARKER + leading + rest;
    if (updated !== original) editor.setLine(line, updated);
  }
}
var IndentPlugin = class extends import_obsidian.Plugin {
  constructor() {
    super(...arguments);
    this.applying = false;
    this.maxNormalizeRetries = 4;
    this.normalizeRetryDelayMs = 50;
  }
  async onload() {
    await this.loadSettings();
    this.registerEvent(
      this.app.workspace.on("editor-change", (editor) => {
        if (!this.settings.enabled) return;
        this.normalizeEditorWithRetries(editor);
      })
    );
    this.registerEvent(
      this.app.workspace.on("file-open", () => {
        if (!this.settings.enabled) return;
        const view = this.app.workspace.getActiveViewOfType(import_obsidian.MarkdownView);
        if (!view) return;
        this.normalizeEditorWithRetries(view.editor);
      })
    );
    this.registerEvent(
      this.app.workspace.on("active-leaf-change", () => {
        if (!this.settings.enabled) return;
        const view = this.app.workspace.getActiveViewOfType(import_obsidian.MarkdownView);
        if (!view) return;
        this.normalizeEditorWithRetries(view.editor);
      })
    );
    this.addCommand({
      id: "clean-zwnj",
      name: "Remove indentation markers (ZWNJ) from current note",
      callback: () => this.cleanZwnjFromActiveEditor()
    });
    this.addSettingTab(new IndentSettingTab(this.app, this));
  }
  cleanZwnjFromActiveEditor() {
    const view = this.app.workspace.getActiveViewOfType(import_obsidian.MarkdownView);
    if (!view) return;
    const editor = view.editor;
    const lineCount = editor.lineCount();
    const changes = [];
    for (let line = 0; line < lineCount; line++) {
      const text = editor.getLine(line);
      const first = text[0];
      if (first && (first === MARKER || LEGACY_MARKERS.has(first))) {
        changes.push({ line, text: text.slice(1) });
      }
    }
    if (!changes.length) return;
    for (const change of changes) {
      editor.setLine(change.line, change.text);
    }
  }
  normalizeEditorWithRetries(editor, attempt = 0) {
    if (this.applying) return;
    window.setTimeout(() => {
      if (this.applying) return;
      this.applying = true;
      try {
        const lineCount = editor.lineCount();
        if (lineCount === 0 && attempt < this.maxNormalizeRetries) {
          this.applying = false;
          window.setTimeout(
            () => this.normalizeEditorWithRetries(editor, attempt + 1),
            this.normalizeRetryDelayMs
          );
          return;
        }
        const cursor = editor.getCursor();
        const hadMarkerBefore = (() => {
          const first = editor.getLine(cursor.line)?.[0];
          return first === MARKER || first != null && LEGACY_MARKERS.has(first);
        })();
        normalizeIndentedLines(editor);
        const hasMarkerAfter = editor.getLine(cursor.line)?.[0] === MARKER;
        const delta = (hasMarkerAfter ? 1 : 0) - (hadMarkerBefore ? 1 : 0);
        editor.setCursor({ line: cursor.line, ch: Math.max(0, cursor.ch + delta) });
      } finally {
        this.applying = false;
      }
    }, 0);
  }
  async updateExtension() {
  }
  getEnabled() {
    return this.settings.enabled;
  }
  async setEnabled(enabled) {
    this.settings.enabled = enabled;
    await this.saveSettings();
  }
  async loadSettings() {
    const data = await this.loadData();
    this.settings = Object.assign({}, DEFAULT_SETTINGS, data ?? {});
  }
  async saveSettings() {
    await this.saveData(this.settings);
    await this.updateExtension();
  }
};
var IndentSettingTab = class extends import_obsidian.PluginSettingTab {
  constructor(app, plugin) {
    super(app, plugin);
    this.plugin = plugin;
  }
  display() {
    const { containerEl } = this;
    containerEl.empty();
    new import_obsidian.Setting(containerEl).setName("Disable indented code blocks").setDesc(
      "Treat indented lines as normal text instead of code blocks in Live Preview."
    ).addToggle(
      (toggle) => toggle.setValue(this.plugin.getEnabled()).onChange(async (value) => {
        await this.plugin.setEnabled(value);
      })
    );
  }
};
//# sourceMappingURL=main.js.map

/* nosourcemap */