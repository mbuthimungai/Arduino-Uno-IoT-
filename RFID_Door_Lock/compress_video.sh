#!/bin/bash
# Compress RFID Door Lock demo video for GitHub
# Converts MOV to MP4 with H.264, targeting ~10MB output

INPUT="IMG_3286.MOV"
OUTPUT="rfid-door-lock-demo.mp4"

if [ ! -f "$INPUT" ]; then
    echo "Error: $INPUT not found"
    exit 1
fi

echo "Compressing $INPUT..."
ffmpeg -i "$INPUT" \
    -vcodec libx264 \
    -crf 28 \
    -preset slow \
    -vf "scale=-2:1080" \
    -acodec aac \
    -b:a 128k \
    -movflags +faststart \
    -y "$OUTPUT"

echo ""
echo "Done!"
echo "Original: $(du -h "$INPUT" | cut -f1)"
echo "Compressed: $(du -h "$OUTPUT" | cut -f1)"
