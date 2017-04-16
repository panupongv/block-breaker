#pragma once

enum RenderLayer {
    BackgroundLayer ,
    EditingSpaceBackgroundLayer,
    EditingSpaceElementLayer,
    EditingSpaceAuraLayer,
    EditingSpacePinLayer,
    DraftBlockLayer,
    BlockLayer,
    PinLayer,
    PanelBackgroundLayer,
    PanelElementLayer,
    TitleLayer
};

enum PositioningMode {
    TopLeft ,
    Center
};

enum UpdateOperation {
    None,
    NewStage ,
    LoadStage ,
<<<<<<< HEAD
    SaveFileOperation ,
    ReplaceFileOperation ,
    Exit
=======
    SaveFile ,
    ReplaceFileOperation ,
    Exit,
    ChangeColor,
    ChangeType
>>>>>>> master-editor
};

enum BlockType {
    normal ,
    breakable ,
    item
};
